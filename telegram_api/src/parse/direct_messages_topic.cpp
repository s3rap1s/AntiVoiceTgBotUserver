#include <types/direct_messages_topic.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

DirectMessagesTopic Parse(const Value& value, To<DirectMessagesTopic>) {
    DirectMessagesTopic obj{};
    obj.topic_id = ParseComplex<Integer>(value["topic_id"]);
    obj.user = ParseComplex<Optional<User>>(value["user"]);
    return obj;
}

}  // namespace tg
