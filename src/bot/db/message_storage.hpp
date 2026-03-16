#pragma once

#include <tg/types/common.hpp>

#include <userver/storages/postgres/cluster.hpp>

#include <optional>
#include <string>
#include <string_view>

namespace tg_bot {

class MessageStorage {
   public:
    struct MessageInfo {
        std::string text;
        int64_t owner_id;
        size_t speed;
    };

    explicit MessageStorage(userver::storages::postgres::ClusterPtr pg_cluster);

    void SaveMessage(std::string_view inline_message_id, std::string_view text, tg::Integer owner_id,
                     size_t speed) const;
    std::optional<MessageInfo> GetMessage(std::string_view inline_message_id) const;

   private:
    userver::storages::postgres::ClusterPtr pg_cluster;
};

}  // namespace tg_bot
