#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct InputPaidMediaVideo {
    String type;
    String media;
    Optional<String> thumbnail;
    Optional<String> cover;
    Optional<Integer> start_timestamp;
    Optional<Integer> width;
    Optional<Integer> height;
    Optional<Integer> duration;
    Optional<Boolean> supports_streaming;
};

InputPaidMediaVideo Parse(const Value& value, To<InputPaidMediaVideo>);

}  // namespace tg
