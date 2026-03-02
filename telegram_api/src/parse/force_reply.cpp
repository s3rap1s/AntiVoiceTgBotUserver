#include <types/force_reply.hpp>

#include "common.hpp"

namespace tg {

ForceReply Parse(const Value& value, To<ForceReply>) {
    ForceReply obj{};
    obj.force_reply = ParseComplex<OptionalTrue>(value["force_reply"]);
    obj.input_field_placeholder =
        ParseComplex<Optional<String>>(value["input_field_placeholder"]);
    obj.selective = ParseComplex<Optional<Boolean>>(value["selective"]);
    return obj;
}

}  // namespace tg
