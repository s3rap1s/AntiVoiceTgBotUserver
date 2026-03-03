#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct Story {
    Chat chat;
    Integer id;
};

Story Parse(const Value& value, To<Story>);

void Serialize(const Story& obj, ValueBuilder& builder);

}  // namespace tg
