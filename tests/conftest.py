import os

import pytest

from testsuite.databases.pgsql import discover

# These hooks patch static config/config_vars before service start in testsuite.
USERVER_CONFIG_HOOKS = [
    'userver_config_bot_token',
    'userver_config_telegram_base_url',
    'userver_pg_config',
]

pytest_plugins = [
    'pytest_userver.plugins.core',
    'pytest_userver.plugins.postgresql',
]


@pytest.fixture(scope='session')
def pgsql_local(service_source_dir, pgsql_local_create, pytestconfig):
    # In service-runner mode we do not bootstrap local test databases.
    if pytestconfig.option.service_runner_mode:
        return pgsql_local_create([])
    databases = discover.find_schemas(
        'telegram_bot',
        [service_source_dir.joinpath('postgresql/schemas')],
    )
    return pgsql_local_create(list(databases.values()))


@pytest.fixture(scope='session')
def userver_pg_config(pytestconfig, pgsql_local):
    if pytestconfig.option.service_runner_mode:
        # Keep start-debug lightweight: do not block startup on PostgreSQL readiness.
        def _patch_config(config_yaml, config_vars):
            components = config_yaml['components_manager']['components']
            postgres = components.get('postgres-db-1')
            if postgres:
                postgres['sync-start'] = False

        return _patch_config

    uri = list(pgsql_local.values())[0].get_uri()

    def _patch_config(config_yaml, config_vars):
        # Point service Postgres component to testsuite-managed DB URI.
        components = config_yaml['components_manager']['components']
        postgres = components.get('postgres-db-1')
        if postgres:
            postgres['dbconnection'] = uri
            postgres.pop('dbalias', None)

    return _patch_config


@pytest.fixture(scope='session')
def userver_config_bot_token():
    def _patch_config(config_yaml, config_vars):
        # Use BOT_TOKEN from environment instead of hardcoded test token.
        token = os.environ.get('BOT_TOKEN')
        if token:
            config_vars['bot-token'] = token

    return _patch_config


@pytest.fixture(scope='session')
def userver_config_telegram_base_url(pytestconfig, mockserver_info):
    def _patch_config(config_yaml, config_vars):
        if pytestconfig.option.service_runner_mode:
            return
        # Redirect Telegram API calls to mockserver for deterministic tests.
        components = config_yaml['components_manager']['components']
        telegram = components.get('telegram-bot')
        if telegram:
            telegram['api-base-url'] = mockserver_info.base_url.rstrip('/')

    return _patch_config


@pytest.fixture
def telegram_api_mock(mockserver):
    # Shared queue of update batches returned by mocked getUpdates.
    token = os.environ['BOT_TOKEN']
    state = {'updates': []}

    @mockserver.json_handler(f'/bot{token}/deleteWebhook')
    def _delete_webhook(request):
        return {'ok': True, 'result': True}

    @mockserver.json_handler(f'/bot{token}/setMyCommands')
    def _set_my_commands(request):
        return {'ok': True, 'result': True}

    @mockserver.json_handler(f'/bot{token}/getMe')
    def _get_me(request):
        return {
            'ok': True,
            'result': {
                'id': 1,
                'is_bot': True,
                'first_name': 'tests-bot',
                'username': 'tests_bot',
            },
        }

    @mockserver.json_handler(f'/bot{token}/getUpdates')
    def _get_updates(request):
        batch = state['updates'].pop(0) if state['updates'] else []
        return {'ok': True, 'result': batch}

    @mockserver.json_handler(f'/bot{token}/sendMessage')
    def _send_message(request):
        return {
            'ok': True,
            'result': {
                'message_id': 1,
                'date': 0,
                'chat': {'id': 1, 'type': 'private'},
            },
        }

    @mockserver.json_handler(f'/bot{token}/answerInlineQuery')
    def _answer_inline_query(request):
        return {'ok': True, 'result': True}

    @mockserver.json_handler(f'/bot{token}/answerCallbackQuery')
    def _answer_callback_query(request):
        return {'ok': True, 'result': True}

    @mockserver.json_handler(f'/bot{token}/editMessageText')
    def _edit_message_text(request):
        return {'ok': True, 'result': True}

    return state


@pytest.fixture
def extra_client_deps(telegram_api_mock):
    # Ensure Telegram API mock routes are installed before service startup.
    pass
