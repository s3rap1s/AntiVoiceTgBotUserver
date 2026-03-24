INSERT INTO bot_schema.user_info(user_id, premium_till)
VALUES($1, CURRENT_DATE + $2::INTEGER)
ON CONFLICT (user_id)
DO UPDATE SET premium_till = CURRENT_DATE + $2::INTEGER