#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

User Parse(const Value& value, To<User>) {
    User obj{};
    obj.id = ParseComplex<Integer>(value["id"]);
    obj.is_bot = ParseComplex<bool>(value["is_bot"]);
    obj.first_name = ParseComplex<String>(value["first_name"]);
    obj.last_name = ParseComplex<Optional<String>>(value["last_name"]);
    obj.username = ParseComplex<Optional<String>>(value["username"]);
    obj.language_code = ParseComplex<Optional<String>>(value["language_code"]);
    obj.is_premium = ParseComplex<OptionalTrue>(value["is_premium"]);
    obj.added_to_attachment_menu = ParseComplex<OptionalTrue>(value["added_to_attachment_menu"]);
    obj.can_join_groups = ParseComplex<Optional<Boolean>>(value["can_join_groups"]);
    obj.can_read_all_group_messages = ParseComplex<Optional<Boolean>>(value["can_read_all_group_messages"]);
    obj.supports_inline_queries = ParseComplex<Optional<Boolean>>(value["supports_inline_queries"]);
    obj.can_connect_to_business = ParseComplex<Optional<Boolean>>(value["can_connect_to_business"]);
    obj.has_main_web_app = ParseComplex<Optional<Boolean>>(value["has_main_web_app"]);
    obj.has_topics_enabled = ParseComplex<Optional<Boolean>>(value["has_topics_enabled"]);
    obj.allows_users_to_create_topics = ParseComplex<Optional<Boolean>>(value["allows_users_to_create_topics"]);
    return obj;
}

void Serialize(const User& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "is_bot", obj.is_bot);
    internal::Put(builder, "first_name", obj.first_name);
    internal::Put(builder, "last_name", obj.last_name);
    internal::Put(builder, "username", obj.username);
    internal::Put(builder, "language_code", obj.language_code);
    internal::Put(builder, "is_premium", obj.is_premium);
    internal::Put(builder, "added_to_attachment_menu", obj.added_to_attachment_menu);
    internal::Put(builder, "can_join_groups", obj.can_join_groups);
    internal::Put(builder, "can_read_all_group_messages", obj.can_read_all_group_messages);
    internal::Put(builder, "supports_inline_queries", obj.supports_inline_queries);
    internal::Put(builder, "can_connect_to_business", obj.can_connect_to_business);
    internal::Put(builder, "has_main_web_app", obj.has_main_web_app);
    internal::Put(builder, "has_topics_enabled", obj.has_topics_enabled);
    internal::Put(builder, "allows_users_to_create_topics", obj.allows_users_to_create_topics);
}

}  // namespace tg
