#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ChatPhoto {
    String small_file_id;
    String small_file_unique_id;
    String big_file_id;
    String big_file_unique_id;
};

ChatPhoto Parse(const Value& value, To<ChatPhoto>);

void Serialize(const ChatPhoto& obj, ValueBuilder& builder);

}  // namespace tg
