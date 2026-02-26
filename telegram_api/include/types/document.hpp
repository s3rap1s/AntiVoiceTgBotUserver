#pragma once

#include "common.hpp"
#include "photo_size.hpp"

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

}  // namespace tg
