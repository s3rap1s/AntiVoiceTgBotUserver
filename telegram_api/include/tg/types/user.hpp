#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct User {
    Integer id;
    bool is_bot;
    String first_name;
    Optional<String> last_name;
    Optional<String> username;
    Optional<String> language_code;
    OptionalTrue is_premium;
    OptionalTrue added_to_attachment_menu;
    Optional<Boolean> can_join_groups;
    Optional<Boolean> can_read_all_group_messages;
    Optional<Boolean> supports_inline_queries;
    Optional<Boolean> can_connect_to_business;
    Optional<Boolean> has_main_web_app;
    Optional<Boolean> has_topics_enabled;
    Optional<Boolean> allows_users_to_create_topics;
};

User Parse(const Value& value, To<User>);

}  // namespace tg
