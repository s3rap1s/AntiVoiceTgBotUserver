SELECT message_text, owner_id, speed
FROM bot_schema.message_storage
WHERE inline_message_id = $1