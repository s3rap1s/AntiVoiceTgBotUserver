#pragma once

#include "bot/db/message_storage.hpp"

#include <tg/bot_api.hpp>

#include <string>
#include <string_view>

void GraduallyUpdateMessage(tg::BotApi& bot, const std::string& inline_message_id, std::string_view full_text,
                            size_t speed, bool is_accumulated, tg_bot::MessageStorage& message_storage);