UPDATE bot_schema.user_info
SET saved_text = NULL
WHERE user_id = $1