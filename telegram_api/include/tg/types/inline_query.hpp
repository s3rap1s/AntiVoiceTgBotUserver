#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/location.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct InlineQuery {
    String id;
    User from;
    String query;
    String offset;
    Optional<String> chat_type;
    Optional<Location> location;
};

InlineQuery Parse(const Value& value, To<InlineQuery>);

void Serialize(const InlineQuery& obj, ValueBuilder& builder);

}  // namespace tg
