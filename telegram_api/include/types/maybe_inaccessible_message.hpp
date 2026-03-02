#pragma once

#include <types/common.hpp>
#include <types/inaccessible_message.hpp>
#include <types/message_ptr.hpp>

namespace tg {

using MaybeInaccessibleMessage = OneOf<MessagePtr, InaccessibleMessage>;

MaybeInaccessibleMessage Parse(const Value& value,
                               To<MaybeInaccessibleMessage>);

}  // namespace tg