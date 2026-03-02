#include <tg/types/voice.hpp>

#include "common.hpp"

namespace tg {

Voice Parse(const Value& value, To<Voice>) {
    Voice obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.duration = ParseComplex<Integer>(value["duration"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

}  // namespace tg
