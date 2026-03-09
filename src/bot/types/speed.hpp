#pragma once

#include <string>

struct SpeedInformation {
    double delay;
    size_t words_per_chunk;
    std::string title;
    std::string speed_str;
};

SpeedInformation GetSpeedInformation(size_t speed);