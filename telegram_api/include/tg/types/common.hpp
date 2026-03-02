#pragma once
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include <userver/formats/json/value.hpp>

namespace tg {

using namespace userver::formats::parse;
using namespace userver::formats::json;

template <typename T>
using Optional = std::optional<T>;

template <typename T>
using Ptr = std::unique_ptr<T>;

template <typename T>
using Array = std::vector<T>;

template <typename... Ts>
using OneOf = std::variant<Ts...>;

using String = std::string;
using Integer = int64_t;
using Float = double;
using OptionalTrue = std::optional<std::monostate>;
using Boolean = bool;

}  // namespace tg
