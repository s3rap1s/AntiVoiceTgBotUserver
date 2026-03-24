#include "user_storage.hpp"

#include "bot/types/speed.hpp"
#include "bot/utils/text_utils.hpp"

#include <tg_bot/sql_queries.hpp>

#include <userver/logging/log.hpp>

namespace tg_bot {

UserStorage::UserStorage(userver::storages::postgres::ClusterPtr pg_cluster) : pg_cluster(std::move(pg_cluster)) {}

void UserStorage::SaveText(tg::Integer user_id, std::string_view text) const try {
    pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kSaveText, user_id, text);

} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to save custom text: user_id=" << user_id << ", error=" << e.what();
    throw;
}

std::optional<std::string> UserStorage::GetText(tg::Integer user_id) const try {
    const auto result =
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kGetText, user_id);
    if (result.IsEmpty()) {
        return std::nullopt;
    }
    const auto row = result.Front();
    return std::string{row["saved_text"].As<std::string>()};
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to get custom text: user_id=" << user_id << ", error=" << e.what();
    throw;
}

void UserStorage::ClearText(tg::Integer user_id) const try {
    pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kClearText, user_id);
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to clear custom text: user_id=" << user_id << ", error=" << e.what();
    throw;
}

void UserStorage::MakeUserPremium(tg::Integer user_id, size_t subscription_duration_days) const try {
    pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kMakeUserPremium, user_id,
                        static_cast<int>(subscription_duration_days));
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to make user premium: user_id=" << user_id << ", error=" << e.what();
    throw;
}

bool UserStorage::IsPremiumUser(tg::Integer user_id) const try {
    const auto result =
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kIsPremiumUser, user_id);
    if (result.IsEmpty()) {
        return false;
    }
    const auto row = result.Front();
    return row["is_premium"].As<bool>();
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to check premium status: user_id=" << user_id << ", error=" << e.what();
    throw;
}

std::optional<UserStorage::State> UserStorage::GetState(tg::Integer user_id) const try {
    const auto result =
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kGetState, user_id);
    if (result.IsEmpty()) {
        return std::nullopt;
    }
    const auto row = result.Front();
    const int state = row["state"].As<int>();
    switch (state) {
        case static_cast<int>(State::kAwaitingCustomSpeed):
            return State::kAwaitingCustomSpeed;
        default:
            LOG_ERROR() << "Unknown user state: user_id=" << user_id << ", state=" << state;
            return std::nullopt;
    }

} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to get user state: user_id=" << user_id << ", error=" << e.what();
    throw;
}

void UserStorage::ChangeState(tg::Integer user_id, std::optional<State> new_state) const try {
    pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kChangeState, user_id,
                        new_state ? std::optional<int>{static_cast<int>(*new_state)} : std::nullopt);
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to change users state: user_id=" << user_id << ", error=" << e.what();
    throw;
}

bool UserStorage::SaveCustomSpeed(tg::Integer user_id, size_t words_per_chunk, float delay_s, std::string title) const
    try {
    const auto result =
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kSaveCustomSpeed, user_id,
                            static_cast<int>(words_per_chunk), static_cast<int>(delay_s * 1000), title);
    return !result.IsEmpty();
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to save custom speed: user_id=" << user_id << ", words_per_chunk=" << words_per_chunk
                << ", delay_s=" << delay_s << ", title=" << title << ", error=" << e.what();
    throw;
}

std::vector<SpeedInformation> UserStorage::GetUserSpeeds(tg::Integer user_id) const try {
    const auto result =
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kGetAvailableSpeeds, user_id);

    std::vector<SpeedInformation> speeds;
    speeds.reserve(result.Size());

    for (const auto& row : result) {
        const auto speed_id = row["speed_id"].As<int>();
        const auto words_per_chunk = static_cast<size_t>(row["words_per_chunk"].As<int>());
        const auto delay_ms = row["delay_ms"].As<int>();
        const auto delay_s = static_cast<float>(delay_ms) / 1000;
        const auto title = row["title"].As<std::string>();
        speeds.emplace_back(speed_id, words_per_chunk, delay_s, title);
    }

    return speeds;
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to get users speeds: user_id=" << user_id << ", error=" << e.what();
    throw;
}

SpeedInformation UserStorage::GetSpeedInformation(size_t speed_id) const try {
    const auto result = pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kGetSpeedInfo,
                                            static_cast<int>(speed_id));
    const auto row = result.Front();
    const auto words_per_chunk = static_cast<size_t>(row["words_per_chunk"].As<int>());
    const auto delay_s = static_cast<float>(row["delay_ms"].As<int>()) / 1000;
    const auto title = row["title"].As<std::string>();
    const auto speed_str = BuildSpeedStr(words_per_chunk, delay_s);
    return SpeedInformation{speed_id, words_per_chunk, delay_s, title};

} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to get speed information: speed_id=" << speed_id << ", error=" << e.what();
    throw;
}

}  // namespace tg_bot
