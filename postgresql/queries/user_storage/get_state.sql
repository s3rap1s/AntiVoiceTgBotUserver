SELECT state
FROM bot_schema.user_info
WHERE user_id = $1 AND state IS NOT NULL
