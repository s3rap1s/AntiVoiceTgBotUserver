#pragma once

#include <string>
#include <string_view>
#include <vector>

size_t ToInteger(std::string_view str);

std::vector<std::string> SplitText(std::string_view text);

std::vector<std::string> SplitTextByWordsCount(std::string_view text, size_t wordsPerChunk);
