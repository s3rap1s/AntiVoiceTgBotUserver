SELECT user_id, words_per_chunk, delay_ms, title 
FROM bot_schema.speed_info
WHERE speed_id = $1