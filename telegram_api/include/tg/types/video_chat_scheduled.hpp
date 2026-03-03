#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct VideoChatScheduled {
    Integer start_date;
};

VideoChatScheduled Parse(const Value& value, To<VideoChatScheduled>);

void Serialize(const VideoChatScheduled& obj, ValueBuilder& builder);

}  // namespace tg
