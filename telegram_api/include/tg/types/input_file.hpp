#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <userver/formats/json/value.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct InputFile {};

InputFile Parse(const userver::formats::json::Value& value, userver::formats::parse::To<InputFile>);

void Serialize(const InputFile& obj, ValueBuilder& builder);

}  // namespace tg
