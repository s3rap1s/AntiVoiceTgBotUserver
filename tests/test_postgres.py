# Start the tests via `make test-debug` or `make test-release`

import pytest
import asyncio


async def _wait_until(predicate, timeout=5.0, interval=0.05):
    deadline = asyncio.get_running_loop().time() + timeout
    while asyncio.get_running_loop().time() < deadline:
        if predicate():
            return
        await asyncio.sleep(interval)
    assert False, 'Condition was not met in time'


def _chosen_inline_update(update_id, user_id, inline_message_id, query='hello world', result_id='0-0'):
    return {
        'update_id': update_id,
        'chosen_inline_result': {
            'result_id': result_id,
            'from': {
                'id': user_id,
                'is_bot': False,
                'first_name': 'Test',
            },
            'query': query,
            'inline_message_id': inline_message_id,
        },
    }


def _message_update(update_id, user_id, text):
    return {
        'update_id': update_id,
        'message': {
            'message_id': update_id,
            'date': 0,
            'chat': {
                'id': user_id,
                'type': 'private',
            },
            'from': {
                'id': user_id,
                'is_bot': False,
                'first_name': 'Test',
            },
            'text': text,
        },
    }


async def test_chosen_inline_result_persists_message(telegram_api_mock, service_client, pgsql):
    inline_message_id = 'inline-msg-1'
    user_id = 101
    query = 'test query'
    telegram_api_mock['updates'].append([_chosen_inline_update(1, user_id, inline_message_id, query=query)])

    response = await service_client.get('/ping')
    assert response.status == 200

    def _row_exists():
        db = pgsql['db_1']
        with db.cursor() as cursor:
            cursor.execute(
                'SELECT message_text, owner_id, speed '
                'FROM bot_schema.message_storage WHERE inline_message_id = %s',
                (inline_message_id,),
            )
            row = cursor.fetchone()
            return row == (query, user_id, 0)

    await _wait_until(_row_exists)


async def test_message_saves_text_to_user_storage(telegram_api_mock, service_client, pgsql):
    user_id = 202
    text = 'hello from message handler'
    telegram_api_mock['updates'].append([_message_update(2, user_id, text)])

    response = await service_client.get('/ping')
    assert response.status == 200

    def _text_saved():
        db = pgsql['db_1']
        with db.cursor() as cursor:
            cursor.execute(
                'SELECT saved_text FROM bot_schema.user_storage WHERE user_id = %s',
                (user_id,),
            )
            row = cursor.fetchone()
            return row == (text,)

    await _wait_until(_text_saved)


async def test_clear_command_nulls_saved_text(telegram_api_mock, service_client, pgsql):
    user_id = 102
    db = pgsql['db_1']
    with db.cursor() as cursor:
        cursor.execute(
            'INSERT INTO bot_schema.user_storage(user_id, saved_text) VALUES (%s, %s) '
            'ON CONFLICT (user_id) DO UPDATE SET saved_text = EXCLUDED.saved_text',
            (user_id, 'to be cleared'),
        )

    telegram_api_mock['updates'].append([_message_update(3, user_id, '/clear')])

    response = await service_client.get('/ping')
    assert response.status == 200

    def _text_cleared():
        with db.cursor() as cursor:
            cursor.execute(
                'SELECT saved_text FROM bot_schema.user_storage WHERE user_id = %s',
                (user_id,),
            )
            row = cursor.fetchone()
            return row == (None,)

    await _wait_until(_text_cleared)

