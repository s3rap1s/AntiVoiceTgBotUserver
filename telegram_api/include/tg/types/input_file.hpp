#pragma once

#include <userver/formats/json/value.hpp>

namespace tg {

struct InputFile {};

InputFile Parse(const userver::formats::json::Value& value,
                userver::formats::parse::To<InputFile>);

}  // namespace tg
