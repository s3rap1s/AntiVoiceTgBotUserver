#include <types/paid_media.hpp>
#include <types/paid_media_info.hpp>

#include "common.hpp"

namespace tg {

PaidMediaInfo Parse(const Value& value, To<PaidMediaInfo>) {
    PaidMediaInfo obj{};
    obj.star_count = ParseComplex<Integer>(value["star_count"]);
    obj.paid_media = ParseComplex<Array<PaidMedia>>(value["paid_media"]);
    return obj;
}

}  // namespace tg
