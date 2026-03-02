#pragma once

#include <memory>

namespace tg {

struct Message;

struct MessageDeleter {
    void operator()(Message* p) const noexcept;
};

using MessagePtr = std::unique_ptr<Message, MessageDeleter>;

}  // namespace tg