#pragma once

#include "bot/types/speed.hpp"

#include <tg/types/bot_command.hpp>

#include <string_view>
#include <vector>

inline constexpr size_t MAX_QUERY_SIZE = 256;
inline constexpr size_t MAX_MESSAGE_SIZE = 4096;
inline constexpr size_t DEFAULT_SPEED_INDEX = 0;

const std::vector<SpeedInformation> SPEEDS = {{5.0, 1, "🐌 Very Slow (Torture Mode)", "5s/word"},
                                              {3.0, 2, "🐢 Slow", "3s/2words"},
                                              {1.5, 3, "🦮 Medium", "1.5s/3words"},
                                              {1.0, 5, "🐆 Fast", "1s/5words"}};

inline tg::BotCommand START_COMMAND = {"/start", "Show initial command"};
inline tg::BotCommand CLEAR_COMMAND = {"/clear", "Clear saved text"};
inline std::vector<tg::BotCommand> COMMANDS = {START_COMMAND, CLEAR_COMMAND};

inline constexpr std::string_view ACCUMULATE_COMMAND = "/a";

inline constexpr std::string_view OFFER_PREM_ARG = "offer_prem";
inline constexpr std::string_view SAVE_TEXT_ARG = "save_text";
