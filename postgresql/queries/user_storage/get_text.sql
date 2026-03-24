SELECT saved_text
FROM bot_schema.user_info
WHERE user_id = $1 AND saved_text IS NOT NULL