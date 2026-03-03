#include <tg/types/passport_file.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const PassportFile& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "file_size", obj.file_size);
    internal::Put(builder, "file_date", obj.file_date);
}

}  // namespace tg
