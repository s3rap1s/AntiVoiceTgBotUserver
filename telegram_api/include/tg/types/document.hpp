#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/photo_size.hpp>

namespace tg {

struct Document {
    String file_id;
    String file_unique_id;
    Optional<PhotoSize> thumbnail;
    Optional<String> file_name;
    Optional<String> mime_type;
    Optional<Integer> file_size;
};

Document Parse(const Value& value, To<Document>);

void Serialize(const Document& obj, ValueBuilder& builder);

}  // namespace tg
