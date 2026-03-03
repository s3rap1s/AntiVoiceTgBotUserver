#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ReactionTypePaid {
    String type;
};

ReactionTypePaid Parse(const Value& value, To<ReactionTypePaid>);

void Serialize(const ReactionTypePaid& obj, ValueBuilder& builder);

}  // namespace tg
