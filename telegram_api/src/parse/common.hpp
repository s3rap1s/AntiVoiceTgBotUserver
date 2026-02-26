#pragma once

#include <types/common.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/formats/parse/to.hpp>

namespace tg {

template <typename T>
T ParseComplex(const userver::formats::json::Value& v);

template <typename T>
Array<T> ParseArray(const userver::formats::json::Value& v);

template <typename T>
Optional<T> ParseOptional(const userver::formats::json::Value& v);

template <typename T>
Ptr<T> ParsePtr(const userver::formats::json::Value& v);

OptionalTrue ParseOptionalTrue(const userver::formats::json::Value& v);

}  // namespace tg