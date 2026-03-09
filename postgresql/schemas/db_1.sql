CREATE SCHEMA IF NOT EXISTS bot_schema;

CREATE TABLE IF NOT EXISTS bot_schema.message_storage (
    inline_message_id TEXT PRIMARY KEY,
    message_text TEXT NOT NULL,
    owner_id INT NOT NULL,
    speed INT NOT NULL
);

CREATE TABLE IF NOT EXISTS bot_schema.user_storage (
    user_id INT PRIMARY KEY,
    saved_text TEXT,
    premium_till DATE
)