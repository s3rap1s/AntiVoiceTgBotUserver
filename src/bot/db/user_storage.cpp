#include "user_storage.hpp"

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

}  // namespace tg_bot
