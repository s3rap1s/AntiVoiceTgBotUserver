#include "text_utils.hpp"

#include <sstream>

std::vector<std::string> SplitText(std::string_view text, char delimiter) {
    std::vector<std::string> words;
    std::string word;
    std::stringstream ss((std::string(text)));
    while (getline(ss, word, delimiter)) {
        words.push_back(word);
    }
    return words;
}

std::vector<std::string> SplitTextByWordsCount(std::string_view text, size_t words_per_chunk) {
    auto words = SplitText(text, ' ');
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

std::string BuildSpeedStr(size_t words_per_chunk, float delay_s) {
    return std::format("{}word{} / {:.1f} sec", (words_per_chunk > 1 ? std::to_string(words_per_chunk) + " " : ""),
                       (words_per_chunk > 1 ? "s" : ""), delay_s);
}