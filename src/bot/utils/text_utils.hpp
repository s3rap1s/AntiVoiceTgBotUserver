#pragma once

#include <charconv>
#include <cmath>
#include <optional>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

template <typename T>
std::optional<T> ToNumber(std::string_view str) {
    T value{};

    const char* begin = str.data();
    const char* end = str.data() + str.size();
    const auto [ptr, ec] = std::from_chars(begin, end, value);
    if (ec != std::errc{} || ptr != end) {
        return std::nullopt;
    }

    if constexpr (std::is_floating_point_v<T>) {
        if (!std::isfinite(value)) {
            return std::nullopt;
        }
    }

    return value;
}

std::vector<std::string> SplitText(std::string_view text, char delimiter);

std::vector<std::string> SplitTextByWordsCount(std::string_view text, size_t wordsPerChunk);

std::string BuildSpeedStr(size_t words_per_chunk, float delay_s);
