#pragma once

#include <tg/types/bot_command.hpp>

#include <string_view>
#include <vector>

inline constexpr size_t MAX_QUERY_SIZE = 256;
inline constexpr size_t MAX_MESSAGE_SIZE = 4096;

inline constexpr size_t DEFAULT_SPEED_INDEX = 1;

inline tg::BotCommand START_COMMAND = {"/start", "Show initial command"};
inline tg::BotCommand CLEAR_COMMAND = {"/clear", "Clear saved text"};
inline tg::BotCommand CREATE_COMMAND = {"/create_speed", "Create custom speed"};
inline tg::BotCommand CANCEL_COMMAND = {"/cancel", "Cancel current action"};
inline std::vector<tg::BotCommand> COMMANDS = {START_COMMAND, CLEAR_COMMAND, CREATE_COMMAND, CANCEL_COMMAND};

inline constexpr std::string_view OFFER_PREM_ARG = "offer_prem";
inline constexpr std::string_view SAVE_TEXT_ARG = "save_text";
