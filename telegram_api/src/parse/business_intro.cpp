#include <tg/types/business_intro.hpp>
#include <tg/types/sticker.hpp>

#include "common.hpp"

namespace tg {

BusinessIntro Parse(const Value& value, To<BusinessIntro>) {
    BusinessIntro obj{};
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.message = ParseComplex<Optional<String>>(value["message"]);
    obj.sticker = ParseComplex<Optional<Sticker>>(value["sticker"]);
    return obj;
}

}  // namespace tg
