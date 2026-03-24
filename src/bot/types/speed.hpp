#pragma once

#include <string>

struct SpeedInformation {
    size_t speed_id;
    size_t words_per_chunk;
    float delay_s;
    std::string title;
};