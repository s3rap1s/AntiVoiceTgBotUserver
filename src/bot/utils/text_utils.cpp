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

std::vector<std::string> SplitTextByWordsCount(std::string_view text, size_t wordsPerChunk, bool isAccumulated) {
    auto words = SplitText(text);
    std::vector<std::string> chunks;

    if (words.empty()) {
        return {};
    }

    size_t currentWordIndex = 0;
    while (currentWordIndex < words.size()) {
        size_t endIndex = std::min(currentWordIndex + wordsPerChunk, words.size());

        std::string chunk;
        if (isAccumulated && !chunks.empty()) chunk = chunks.back() + " ";

        for (size_t i = currentWordIndex; i < endIndex; ++i) {
            if (i > currentWordIndex) {
                chunk += " ";
            }
            chunk += words[i];
        }
        currentWordIndex = endIndex;
        chunks.push_back(chunk);
    }
    return chunks;
}