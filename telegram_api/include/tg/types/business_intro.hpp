#pragma once

#include <tg/types/common.hpp>
#include <tg/types/sticker.hpp>

namespace tg {

struct BusinessIntro {
    Optional<String> title;
    Optional<String> message;
    Optional<Sticker> sticker;
};

BusinessIntro Parse(const Value& value, To<BusinessIntro>);

}  // namespace tg
