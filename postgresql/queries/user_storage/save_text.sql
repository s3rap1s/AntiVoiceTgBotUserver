INSERT INTO bot_schema.user_storage(user_id, saved_text)
VALUES($1, $2)
ON CONFLICT (user_id)
DO UPDATE SET saved_text = EXCLUDED.saved_text