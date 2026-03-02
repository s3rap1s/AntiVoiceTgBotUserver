#pragma once

#include <tg/types/common.hpp>
#include <tg/types/inaccessible_message.hpp>
#include <tg/types/message_ptr.hpp>

namespace tg {

using MaybeInaccessibleMessage = OneOf<MessagePtr, InaccessibleMessage>;

MaybeInaccessibleMessage Parse(const Value& value,
                               To<MaybeInaccessibleMessage>);

}  // namespace tg