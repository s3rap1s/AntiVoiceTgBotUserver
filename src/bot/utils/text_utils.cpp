#include "text_utils.hpp"

#include <sstream>
#include <string_view>

size_t ToInteger(std::string_view str) {
    std::stringstream ss((std::string(str)));
    size_t res{};
    ss >> res;
    return res;
}

std::vector<std::string> SplitText(std::string_view text) {
    std::vector<std::string> words;
    std::stringstream ss((std::string(text)));
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

std::vector<std::string> SplitTextByWordsCount(std::string_view text, size_t words_per_chunk) {
    auto words = SplitText(text);
    std::vector<std::string> chunks;

    if (words.empty()) {
        return {};
    }

    size_t curr_word_idx = 0;
    while (curr_word_idx < words.size()) {
        size_t end_idx = std::min(curr_word_idx + words_per_chunk, words.size());

        std::string chunk;
        for (size_t i = curr_word_idx; i < end_idx; ++i) {
            chunk += words[i] + (i + 1 < end_idx ? " " : "");
        }
        curr_word_idx = end_idx;
        chunks.push_back(chunk);
    }
    return chunks;
}