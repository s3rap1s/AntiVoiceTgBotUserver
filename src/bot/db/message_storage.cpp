#include "message_storage.hpp"

#include <userver/logging/log.hpp>
#include <userver/storages/postgres/component.hpp>

namespace tg_bot {

MessageStorage::MessageStorage(const userver::components::ComponentContext& context, std::string db_component_name)
    : pg_cluster(context.FindComponent<userver::components::Postgres>(db_component_name).GetCluster()) {}

bool MessageStorage::SaveMessage(std::string_view inline_message_id, std::string_view text, tg::Integer owner_id,
                                 size_t speed) const {
    try {
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                            "INSERT INTO bot_schema.message_storage(inline_message_id, message_text, owner_id, speed) "
                            "VALUES($1, $2, $3, $4)",
                            inline_message_id, text, owner_id, static_cast<int>(speed));
        return true;
    } catch (const std::exception& e) {
        LOG_ERROR() << "Failed to save inline message: id=" << inline_message_id << ", error=" << e.what();
        return false;
    }
}

std::optional<MessageStorage::MessageInfo> MessageStorage::GetMessage(std::string_view inline_message_id) const {
    const auto result = pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                                            "SELECT message_text, owner_id, speed "
                                            "FROM bot_schema.message_storage "
                                            "WHERE inline_message_id = $1",
                                            inline_message_id);
    if (result.IsEmpty()) {
        return std::nullopt;
    }
    const auto row = result.Front();
    return MessageStorage::MessageInfo{.text = row["message_text"].As<std::string>(),
                                       .owner_id = row["owner_id"].As<int64_t>(),
                                       .speed = static_cast<size_t>(row["speed"].As<int>())};
}

bool MessageStorage::ForgetMessage(std::string_view inline_message_id) const {
    try {
        const auto result = pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster,
                                                "DELETE FROM bot_schema.message_storage "
                                                "WHERE inline_message_id = $1 "
                                                "RETURNING 1",
                                                inline_message_id);
        return !result.IsEmpty();
    } catch (const std::exception& e) {
        LOG_ERROR() << "Failed to forget inline message: id=" << inline_message_id << ", error=" << e.what();
        return false;
    }
}

}  // namespace tg_bot
