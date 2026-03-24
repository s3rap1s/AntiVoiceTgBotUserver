SELECT premium_till IS NOT NULL AND premium_till >= CURRENT_DATE 
AS is_premium
FROM bot_schema.user_info
WHERE user_id = $1