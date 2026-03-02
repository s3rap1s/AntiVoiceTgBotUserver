#include <types/photo_size.hpp>

#include "common.hpp"

namespace tg {

PhotoSize Parse(const Value& value, To<PhotoSize>) {
    PhotoSize obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.width = ParseComplex<Integer>(value["width"]);
    obj.height = ParseComplex<Integer>(value["height"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

}  // namespace tg
