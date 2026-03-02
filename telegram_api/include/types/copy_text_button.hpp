#pragma once

#include <types/common.hpp>

namespace tg {

struct CopyTextButton {
    String text;
};

CopyTextButton Parse(const Value& value, To<CopyTextButton>);

}  // namespace tg
