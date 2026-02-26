#pragma once

#include "chat.hpp"
#include "common.hpp"

namespace tg {

struct Story {
    Chat chat;
    Integer id;
};

Story Parse(const Value& value, To<Story>);

}  // namespace tg
