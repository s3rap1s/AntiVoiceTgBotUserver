INSERT INTO bot_schema.speed_info(user_id, words_per_chunk, delay_ms, title)
VALUES($1, $2, $3, $4)
ON CONFLICT (user_id, title) DO NOTHING
RETURNING speed_id
