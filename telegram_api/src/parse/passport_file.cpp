#include <tg/types/passport_file.hpp>

#include "common.hpp"

namespace tg {

PassportFile Parse(const Value& value, To<PassportFile>) {
    PassportFile obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.file_size = ParseComplex<Integer>(value["file_size"]);
    obj.file_date = ParseComplex<Integer>(value["file_date"]);
    return obj;
}

}  // namespace tg
