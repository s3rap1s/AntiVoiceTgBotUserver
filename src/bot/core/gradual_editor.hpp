#pragma once

#include <tg/bot_api.hpp>

#include <string>
#include <string_view>

void GraduallyUpdateMessage(tg::BotApi& bot, const std::string& inline_message_id, std::string_view full_text,
                            size_t speed);