#include <tg/types/force_reply.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ForceReply Parse(const Value& value, To<ForceReply>) {
    ForceReply obj{};
    obj.force_reply = ParseComplex<OptionalTrue>(value["force_reply"]);
    obj.input_field_placeholder = ParseComplex<Optional<String>>(value["input_field_placeholder"]);
    obj.selective = ParseComplex<Optional<Boolean>>(value["selective"]);
    return obj;
}

void Serialize(const ForceReply& obj, ValueBuilder& builder) {
    internal::Put(builder, "force_reply", obj.force_reply);
    internal::Put(builder, "input_field_placeholder", obj.input_field_placeholder);
    internal::Put(builder, "selective", obj.selective);
}

}  // namespace tg
