UPDATE bot_schema.user_storage
SET saved_text = NULL
WHERE user_id = $1