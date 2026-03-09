#include "user_storage.hpp"

#include <userver/logging/log.hpp>
#include <userver/storages/postgres/component.hpp>

namespace tg_bot {

UserStorage::UserStorage(const userver::components::ComponentContext& context, std::string db_component_name)
    : pg_cluster(context.FindComponent<userver::components::Postgres>(db_component_name).GetCluster()) {}

bool UserStorage::SaveText(tg::Integer user_id, std::string_view text) const {
    try {
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                            "INSERT INTO bot_schema.user_storage(user_id, saved_text) "
                            "VALUES($1, $2) "
                            "ON CONFLICT (user_id) "
                            "DO UPDATE SET saved_text = EXCLUDED.saved_text",
                            user_id, text);
        return true;
    } catch (const std::exception& e) {
        LOG_ERROR() << "Failed to save custom text: user_id=" << user_id << ", error=" << e.what();
        return false;
    }
}

std::optional<std::string> UserStorage::GetText(tg::Integer user_id) const {
    const auto result = pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                                            "SELECT saved_text "
                                            "FROM bot_schema.user_storage "
                                            "WHERE user_id = $1 AND saved_text IS NOT NULL",
                                            user_id);
    if (result.IsEmpty()) {
        return std::nullopt;
    }
    const auto row = result.Front();
    return std::string{row["saved_text"].As<std::string>()};
}

bool UserStorage::ClearText(tg::Integer user_id) const {
    try {
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                            "UPDATE bot_schema.user_storage "
                            "SET saved_text = NULL "
                            "WHERE user_id = $1",
                            user_id);
        return true;
    } catch (const std::exception& e) {
        LOG_ERROR() << "Failed to clear custom text: user_id=" << user_id << ", error=" << e.what();
        return false;
    }
}

bool UserStorage::MakeUserPremium(tg::Integer user_id, size_t subscription_duration) const {
    try {
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                            "INSERT INTO bot_schema.user_storage(user_id, premium_till) "
                            "VALUES($1, CURRENT_DATE + $2::INTEGER) "
                            "ON CONFLICT (user_id) "
                            "DO UPDATE SET premium_till = CURRENT_DATE + $2::INTEGER",
                            user_id, static_cast<int>(subscription_duration));
        return true;
    } catch (const std::exception& e) {
        LOG_ERROR() << "Failed to make user premium: user_id=" << user_id << ", error=" << e.what();
        return false;
    }
}

bool UserStorage::IsPremiumUser(tg::Integer user_id) const {
    try {
        const auto result = pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                                                "SELECT premium_till IS NOT NULL AND premium_till >= CURRENT_DATE "
                                                "AS is_premium "
                                                "FROM bot_schema.user_storage "
                                                "WHERE user_id = $1",
                                                user_id);
        if (result.IsEmpty()) {
            return false;
        }
        const auto row = result.Front();
        return row["is_premium"].As<bool>();
    } catch (const std::exception& e) {
        LOG_ERROR() << "Failed to check premium status: user_id=" << user_id << ", error=" << e.what();
        return false;
    }
}

}  // namespace tg_bot
