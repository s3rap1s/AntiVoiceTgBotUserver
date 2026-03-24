SELECT message_text, owner_id, speed
FROM bot_schema.message_info
WHERE inline_message_id = $1