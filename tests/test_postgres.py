# Start the tests via `make test-debug` or `make test-release`

import asyncio
import datetime
import pytest


pytestmark = pytest.mark.uservice_oneshot


async def _wait_until(predicate, timeout=5.0, interval=0.05):
    deadline = asyncio.get_running_loop().time() + timeout
    while asyncio.get_running_loop().time() < deadline:
        if predicate():
            return
        await asyncio.sleep(interval)
    assert False, 'Condition was not met in time'


def _inline_query_update(update_id, user_id, query='', inline_query_id='inline-query-1'):
    return {
        'update_id': update_id,
        'inline_query': {
            'id': inline_query_id,
            'from': {
                'id': user_id,
                'is_bot': False,
                'first_name': 'Test',
            },
            'query': query,
            'offset': '',
        },
    }


def _chosen_inline_update(update_id, user_id, inline_message_id, query='', result_id='0'):
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


def _callback_query_update(update_id, user_id, inline_message_id, data, callback_query_id='callback-query-1'):
    return {
        'update_id': update_id,
        'callback_query': {
            'id': callback_query_id,
            'chat_instance': 'test-chat-instance',
            'from': {
                'id': user_id,
                'is_bot': False,
                'first_name': 'Test',
            },
            'inline_message_id': inline_message_id,
            'data': data,
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


async def _poll_service(service_client):
    response = await service_client.post('/telegram/webhook', json={})
    assert response.status == 400


async def _send_update(service_client, update):
    response = await service_client.post('/telegram/webhook', json=update)
    assert response.status == 200


def _fetchone(pgsql, query, params):
    db = pgsql['db_1']
    with db.cursor() as cursor:
        cursor.execute(query, params)
        return cursor.fetchone()


def _execute(pgsql, query, params):
    db = pgsql['db_1']
    with db.cursor() as cursor:
        cursor.execute(query, params)


def _get_saved_text(pgsql, user_id):
    return _fetchone(
        pgsql,
        'SELECT saved_text FROM bot_schema.user_storage WHERE user_id = %s',
        (user_id,),
    )


def _get_message_info(pgsql, inline_message_id):
    return _fetchone(
        pgsql,
        'SELECT message_text, owner_id, speed '
        'FROM bot_schema.message_storage WHERE inline_message_id = %s',
        (inline_message_id,),
    )


def _get_premium_till(pgsql, user_id):
    return _fetchone(
        pgsql,
        'SELECT premium_till FROM bot_schema.user_storage WHERE user_id = %s',
        (user_id,),
    )


async def test_save_text_query(telegram_api_mock, service_client, pgsql):
    user_id = 101
    text = 'saved text from bot message'

    await _send_update(service_client, _message_update(1, user_id, text))

    await _wait_until(lambda: _get_saved_text(pgsql, user_id) == (text,))


async def test_get_text_query(telegram_api_mock, service_client, pgsql):
    user_id = 102
    text = 'saved text from storage'
    _execute(
        pgsql,
        'INSERT INTO bot_schema.user_storage(user_id, saved_text) VALUES (%s, %s) '
        'ON CONFLICT (user_id) DO UPDATE SET saved_text = EXCLUDED.saved_text',
        (user_id, text),
    )

    await _send_update(service_client, _inline_query_update(2, user_id))

    await _wait_until(lambda: bool(telegram_api_mock['answer_inline_queries']))
    request = telegram_api_mock['answer_inline_queries'][-1]
    assert len(request['results']) == 4
    assert any(text in result['description'] for result in request['results'])


async def test_save_message_query(telegram_api_mock, service_client, pgsql):
    user_id = 103
    inline_message_id = 'inline-msg-save'
    text = 'chosen inline text'

    await _send_update(service_client, _chosen_inline_update(3, user_id, inline_message_id, query=text))

    await _wait_until(lambda: _get_message_info(pgsql, inline_message_id) == (text, user_id, 0))


async def test_get_message_query(telegram_api_mock, service_client, pgsql):
    user_id = 104
    inline_message_id = 'inline-msg-get'
    text = 'message from storage'
    _execute(
        pgsql,
        'INSERT INTO bot_schema.message_storage(inline_message_id, message_text, owner_id, speed) '
        'VALUES (%s, %s, %s, %s)',
        (inline_message_id, text, user_id, 0),
    )

    await _send_update(service_client, _callback_query_update(4, user_id, inline_message_id, 'show_full'))

    await _wait_until(lambda: bool(telegram_api_mock['answer_callback_queries']))
    request = telegram_api_mock['answer_callback_queries'][-1]
    assert request['text'] == text
    assert request['show_alert'] is True


async def test_clear_text_query(telegram_api_mock, service_client, pgsql):
    user_id = 105
    _execute(
        pgsql,
        'INSERT INTO bot_schema.user_storage(user_id, saved_text) VALUES (%s, %s) '
        'ON CONFLICT (user_id) DO UPDATE SET saved_text = EXCLUDED.saved_text',
        (user_id, 'to be cleared'),
    )

    await _send_update(service_client, _message_update(5, user_id, '/clear'))

    await _wait_until(lambda: _get_saved_text(pgsql, user_id) == (None,))


async def test_make_user_premium_query(telegram_api_mock, service_client, pgsql):
    user_id = 106

    await _send_update(service_client, _message_update(6, user_id, 'makeMePremiumUser'))

    expected = datetime.date.today() + datetime.timedelta(days=1)
    await _wait_until(lambda: _get_premium_till(pgsql, user_id) == (expected,))


async def test_is_premium_user_positive_query(telegram_api_mock, service_client, pgsql):
    owner_id = 107
    reader_id = 108
    inline_message_id = 'inline-msg-premium'
    text = 'premium-only'

    _execute(
        pgsql,
        'INSERT INTO bot_schema.message_storage(inline_message_id, message_text, owner_id, speed) '
        'VALUES (%s, %s, %s, %s)',
        (inline_message_id, text, owner_id, 0),
    )
    _execute(
        pgsql,
        'INSERT INTO bot_schema.user_storage(user_id, premium_till) VALUES (%s, CURRENT_DATE + 1) '
        'ON CONFLICT (user_id) DO UPDATE SET premium_till = CURRENT_DATE + 1',
        (reader_id,),
    )

    await _send_update(service_client, _callback_query_update(7, reader_id, inline_message_id, 'show_full'))

    await _wait_until(lambda: bool(telegram_api_mock['answer_callback_queries']))
    request = telegram_api_mock['answer_callback_queries'][-1]
    assert request['text'] == text
    assert request['show_alert'] is True


async def test_is_premium_user_negative_query(telegram_api_mock, service_client, pgsql):
    owner_id = 109
    reader_id = 110
    inline_message_id = 'inline-msg-premium-negative'

    _execute(
        pgsql,
        'INSERT INTO bot_schema.message_storage(inline_message_id, message_text, owner_id, speed) '
        'VALUES (%s, %s, %s, %s)',
        (inline_message_id, 'premium-only', owner_id, 0),
    )
    _execute(
        pgsql,
        'INSERT INTO bot_schema.user_storage(user_id, premium_till) VALUES (%s, CURRENT_DATE + 1) '
        'ON CONFLICT (user_id) DO UPDATE SET premium_till = CURRENT_DATE + 1',
        (owner_id,),
    )

    await _send_update(service_client, _callback_query_update(8, reader_id, inline_message_id, 'show_full'))

    await _wait_until(lambda: bool(telegram_api_mock['answer_callback_queries']))
    request = telegram_api_mock['answer_callback_queries'][-1]
    assert request['url'] == 't.me/tests_bot?start=offer_prem'
    assert request['show_alert'] is True


async def test_listen_continues_after_message_not_modified(telegram_api_mock, service_client, pgsql):
    user_id = 111
    inline_message_id = 'inline-msg-listen-repeat'
    text = 'one two three four five one two three four five end'
    speed = 3

    _execute(
        pgsql,
        'INSERT INTO bot_schema.message_storage(inline_message_id, message_text, owner_id, speed) '
        'VALUES (%s, %s, %s, %s)',
        (inline_message_id, text, user_id, speed),
    )

    await _send_update(service_client, _callback_query_update(9, user_id, inline_message_id, 'listen'))

    await _wait_until(lambda: bool(telegram_api_mock['answer_callback_queries']))
    callback_request = telegram_api_mock['answer_callback_queries'][-1]
    assert callback_request['callback_query_id'] == 'callback-query-1'

    await _wait_until(
        lambda: any(
            request.get('inline_message_id') == inline_message_id
            and request.get('text') == '<i>End of the message</i>'
            for request in telegram_api_mock['edit_message_texts']
        ),
        timeout=4.0,
    )
