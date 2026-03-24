#pragma once

#include "bot/types/speed.hpp"

#include <tg/types/common.hpp>

#include <userver/storages/postgres/cluster.hpp>

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace tg_bot {

class UserStorage {
   public:
    enum class State {
        kAwaitingCustomSpeed = 1,
    };

    explicit UserStorage(userver::storages::postgres::ClusterPtr pg_cluster);

    void SaveText(tg::Integer user_id, std::string_view text) const;
    std::optional<std::string> GetText(tg::Integer user_id) const;
    void ClearText(tg::Integer user_id) const;

    void MakeUserPremium(tg::Integer user_id, size_t subscription_duration_days) const;
    bool IsPremiumUser(tg::Integer user_id) const;

    void ChangeState(tg::Integer user_id, std::optional<State> new_state) const;
    std::optional<State> GetState(tg::Integer user_id) const;

    bool SaveCustomSpeed(tg::Integer user_id, size_t words_per_chunk, float delay_s, std::string title) const;
    std::vector<SpeedInformation> GetUserSpeeds(tg::Integer user_id) const;
    SpeedInformation GetSpeedInformation(size_t speed_id) const;

   private:
    userver::storages::postgres::ClusterPtr pg_cluster;
};

}  // namespace tg_bot
