SELECT speed_id, words_per_chunk, delay_ms, title
FROM bot_schema.speed_info
WHERE user_id IS NULL OR user_id = $1
ORDER BY user_id NULLS FIRST, speed_id
