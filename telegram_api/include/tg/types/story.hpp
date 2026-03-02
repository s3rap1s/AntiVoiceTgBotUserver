#pragma once

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct Story {
    Chat chat;
    Integer id;
};

Story Parse(const Value& value, To<Story>);

}  // namespace tg
