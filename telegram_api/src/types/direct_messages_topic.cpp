#include <tg/types/direct_messages_topic.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

DirectMessagesTopic Parse(const Value& value, To<DirectMessagesTopic>) {
    DirectMessagesTopic obj{};
    obj.topic_id = ParseComplex<Integer>(value["topic_id"]);
    obj.user = ParseComplex<Optional<User>>(value["user"]);
    return obj;
}

void Serialize(const DirectMessagesTopic& obj, ValueBuilder& builder) {
    internal::Put(builder, "topic_id", obj.topic_id);
    internal::Put(builder, "user", obj.user);
}

}  // namespace tg
