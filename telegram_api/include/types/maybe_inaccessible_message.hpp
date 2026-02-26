#pragma once

#include "inaccessible_message.hpp"

namespace tg {

struct Message;

using MaybeInaccessibleMessage = OneOf<Ptr<Message>, InaccessibleMessage>;

MaybeInaccessibleMessage Parse(const Value& value,
                               To<MaybeInaccessibleMessage>);

}  // namespace tg
