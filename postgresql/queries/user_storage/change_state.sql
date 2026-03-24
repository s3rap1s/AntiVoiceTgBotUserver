INSERT INTO bot_schema.user_info(user_id, state)
VALUES($1, $2)
ON CONFLICT (user_id)
DO UPDATE SET state = EXCLUDED.state
