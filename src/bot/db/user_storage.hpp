#pragma once

#include <tg/types/common.hpp>

#include <userver/storages/postgres/cluster.hpp>

#include <optional>
#include <string>
#include <string_view>

namespace tg_bot {

class UserStorage {
   public:
    explicit UserStorage(userver::storages::postgres::ClusterPtr pg_cluster);

    void SaveText(tg::Integer user_id, std::string_view text) const;
    std::optional<std::string> GetText(tg::Integer user_id) const;
    void ClearText(tg::Integer user_id) const;

    void MakeUserPremium(tg::Integer user_id, size_t subscription_duration_days) const;
    bool IsPremiumUser(tg::Integer user_id) const;

   private:
    userver::storages::postgres::ClusterPtr pg_cluster;
};

}  // namespace tg_bot
