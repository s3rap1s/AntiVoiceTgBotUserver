#include <tg/types/maybe_inaccessible_message.hpp>
#include <tg/types/message.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MaybeInaccessibleMessage Parse(const Value& value, To<MaybeInaccessibleMessage>) {
    const auto date = value["date"].As<Integer>(-1);

    if (date == 0) {  // then its InaccessibleMessage
        return MaybeInaccessibleMessage{std::in_place_type<InaccessibleMessage>,
                                        ParseComplex<InaccessibleMessage>(value)};
    }

    Message msg = ParseComplex<Message>(value);
    MessagePtr ptr{new Message(std::move(msg))};

    return MaybeInaccessibleMessage{std::in_place_type<MessagePtr>, std::move(ptr)};
}

void Serialize(const MaybeInaccessibleMessage& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg