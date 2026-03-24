#pragma once

#include "bot/db/user_storage.hpp"

#include <tg/bot_api.hpp>

#include <string>
#include <string_view>

namespace tg_bot {

void GraduallyUpdateMessage(tg::BotApi& bot, const std::string& inline_message_id, std::string_view full_text,
                            size_t speed_id, UserStorage& user_storage);
}
