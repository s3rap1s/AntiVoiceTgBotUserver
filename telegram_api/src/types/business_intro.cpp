#include <tg/types/business_intro.hpp>
#include <tg/types/sticker.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BusinessIntro Parse(const Value& value, To<BusinessIntro>) {
    BusinessIntro obj{};
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.message = ParseComplex<Optional<String>>(value["message"]);
    obj.sticker = ParseComplex<Optional<Sticker>>(value["sticker"]);
    return obj;
}

void Serialize(const BusinessIntro& obj, ValueBuilder& builder) {
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "message", obj.message);
    internal::Put(builder, "sticker", obj.sticker);
}

}  // namespace tg
