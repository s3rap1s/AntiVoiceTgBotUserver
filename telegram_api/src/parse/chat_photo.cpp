#include <tg/types/chat_photo.hpp>

#include "common.hpp"

namespace tg {

ChatPhoto Parse(const Value& value, To<ChatPhoto>) {
    ChatPhoto obj{};
    obj.small_file_id = ParseComplex<String>(value["small_file_id"]);
    obj.small_file_unique_id =
        ParseComplex<String>(value["small_file_unique_id"]);
    obj.big_file_id = ParseComplex<String>(value["big_file_id"]);
    obj.big_file_unique_id = ParseComplex<String>(value["big_file_unique_id"]);
    return obj;
}

}  // namespace tg
