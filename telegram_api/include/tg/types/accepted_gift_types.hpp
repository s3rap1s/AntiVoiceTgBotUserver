#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct AcceptedGiftTypes {
    Boolean unlimited_gifts;
    Boolean limited_gifts;
    Boolean unique_gifts;
    Boolean premium_subscription;
    Boolean gifts_from_channels;
};

AcceptedGiftTypes Parse(const Value& value, To<AcceptedGiftTypes>);

void Serialize(const AcceptedGiftTypes& obj, ValueBuilder& builder);

}  // namespace tg
