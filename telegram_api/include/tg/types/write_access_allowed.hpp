#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct WriteAccessAllowed {
    Optional<Boolean> from_request;
    Optional<String> web_app_name;
    Optional<Boolean> from_attachment_menu;
};

WriteAccessAllowed Parse(const Value& value, To<WriteAccessAllowed>);

void Serialize(const WriteAccessAllowed& obj, ValueBuilder& builder);

}  // namespace tg
