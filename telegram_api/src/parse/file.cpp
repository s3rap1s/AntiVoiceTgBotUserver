#include <types/file.hpp>

#include "common.hpp"

namespace tg {

File Parse(const Value& value, To<File>) {
    File obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    obj.file_path = ParseComplex<Optional<String>>(value["file_path"]);
    return obj;
}

}  // namespace tg
