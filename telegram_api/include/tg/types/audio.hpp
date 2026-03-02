#pragma once

#include <tg/types/common.hpp>
#include <tg/types/photo_size.hpp>

namespace tg {

struct Audio {
    String file_id;
    String file_unique_id;
    Integer duration;
    Optional<String> performer;
    Optional<String> title;
    Optional<String> file_name;
    Optional<String> mime_type;
    Optional<Integer> file_size;
    Optional<PhotoSize> thumbnail;
};

Audio Parse(const Value& value, To<Audio>);

}  // namespace tg
