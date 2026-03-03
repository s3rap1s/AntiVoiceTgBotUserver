#pragma once

#include <memory>

#include <userver/formats/json/value_builder.hpp>

namespace tg {

struct Message;

void Serialize(const Message& obj, userver::formats::json::ValueBuilder& builder);

struct MessageDeleter {
    void operator()(Message* p) const noexcept;
};

using MessagePtr = std::unique_ptr<Message, MessageDeleter>;

}  // namespace tg
