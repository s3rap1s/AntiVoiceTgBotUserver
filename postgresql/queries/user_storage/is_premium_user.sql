SELECT premium_till IS NOT NULL AND premium_till >= CURRENT_DATE 
AS is_premium
FROM bot_schema.user_storage
WHERE user_id = $1