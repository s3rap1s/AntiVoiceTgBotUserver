#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/location.hpp>

namespace tg {

struct ChatLocation {
    Location location;
    String address;
};

ChatLocation Parse(const Value& value, To<ChatLocation>);

void Serialize(const ChatLocation& obj, ValueBuilder& builder);

}  // namespace tg
