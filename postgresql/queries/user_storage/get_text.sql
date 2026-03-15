SELECT saved_text
FROM bot_schema.user_storage
WHERE user_id = $1 AND saved_text IS NOT NULL