#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/sticker.hpp>

namespace tg {

struct BusinessIntro {
    Optional<String> title;
    Optional<String> message;
    Optional<Sticker> sticker;
};

BusinessIntro Parse(const Value& value, To<BusinessIntro>);

void Serialize(const BusinessIntro& obj, ValueBuilder& builder);

}  // namespace tg
