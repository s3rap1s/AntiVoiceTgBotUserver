#include "speed.hpp"

#include "bot/config.hpp"

SpeedInformation GetSpeedInformation(size_t idx) {
    if (idx >= SPEEDS.size()) {
        idx = DEFAULT_SPEED_INDEX;
    }
    return SPEEDS[idx];
}