#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct WebhookInfo {
    String url;
    Boolean has_custom_certificate;
    Integer pending_update_count;
    Optional<String> ip_address;
    Optional<Integer> last_error_date;
    Optional<String> last_error_message;
    Optional<Integer> last_synchronization_error_date;
    Optional<Integer> max_connections;
    Optional<Array<String>> allowed_updates;
};

WebhookInfo Parse(const Value& value, To<WebhookInfo>);

void Serialize(const WebhookInfo& obj, ValueBuilder& builder);

}  // namespace tg
