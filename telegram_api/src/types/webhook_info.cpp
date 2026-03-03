#include <tg/types/webhook_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

WebhookInfo Parse(const Value& value, To<WebhookInfo>) {
    WebhookInfo obj{};
    obj.url = ParseComplex<String>(value["url"]);
    obj.has_custom_certificate = ParseComplex<Boolean>(value["has_custom_certificate"]);
    obj.pending_update_count = ParseComplex<Integer>(value["pending_update_count"]);
    obj.ip_address = ParseComplex<Optional<String>>(value["ip_address"]);
    obj.last_error_date = ParseComplex<Optional<Integer>>(value["last_error_date"]);
    obj.last_error_message = ParseComplex<Optional<String>>(value["last_error_message"]);
    obj.last_synchronization_error_date = ParseComplex<Optional<Integer>>(value["last_synchronization_error_date"]);
    obj.max_connections = ParseComplex<Optional<Integer>>(value["max_connections"]);
    obj.allowed_updates = ParseComplex<Optional<Array<String>>>(value["allowed_updates"]);
    return obj;
}

void Serialize(const WebhookInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "url", obj.url);
    internal::Put(builder, "has_custom_certificate", obj.has_custom_certificate);
    internal::Put(builder, "pending_update_count", obj.pending_update_count);
    internal::Put(builder, "ip_address", obj.ip_address);
    internal::Put(builder, "last_error_date", obj.last_error_date);
    internal::Put(builder, "last_error_message", obj.last_error_message);
    internal::Put(builder, "last_synchronization_error_date", obj.last_synchronization_error_date);
    internal::Put(builder, "max_connections", obj.max_connections);
    internal::Put(builder, "allowed_updates", obj.allowed_updates);
}

}  // namespace tg
