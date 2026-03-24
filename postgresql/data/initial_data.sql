INSERT INTO bot_schema.speed_info(user_id, words_per_chunk, delay_ms, title)
  VALUES
  (NULL, 1, 5000, '🐌 Very Slow'),
  (NULL, 2, 3000, '🐢 Slow'),
  (NULL, 3, 1500, '🦮 Medium'),
  (NULL, 5, 1000, '🐆 Fast')
  ON CONFLICT DO NOTHING;