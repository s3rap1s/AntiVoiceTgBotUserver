CREATE SCHEMA IF NOT EXISTS bot_schema;

CREATE TABLE IF NOT EXISTS bot_schema.message_info (
    inline_message_id TEXT PRIMARY KEY,
    message_text TEXT NOT NULL,
    owner_id INT NOT NULL,
    speed INT NOT NULL
);

CREATE TABLE IF NOT EXISTS bot_schema.user_info (
    user_id INT PRIMARY KEY,
    saved_text TEXT,
    premium_till DATE,
    state INT
);

CREATE TABLE IF NOT EXISTS bot_schema.speed_info (
    speed_id SERIAL PRIMARY KEY,
    user_id INT,
    words_per_chunk INT NOT NULL CHECK (words_per_chunk > 0),
    delay_ms INT NOT NULL CHECK (delay_ms > 0),
    title TEXT NOT NULL,
    UNIQUE (user_id, title)
);
