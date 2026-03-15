#include "message_storage.hpp"

#include <tg_bot/sql_queries.hpp>

#include <userver/logging/log.hpp>
#include <userver/storages/postgres/component.hpp>

namespace tg_bot {

MessageStorage::MessageStorage(const userver::components::ComponentContext& context, std::string db_component_name)
    : pg_cluster(context.FindComponent<userver::components::Postgres>(db_component_name).GetCluster()) {}

void MessageStorage::SaveMessage(std::string_view inline_message_id, std::string_view text, tg::Integer owner_id,
                                 size_t speed) const try {
    pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kSaveMessage, inline_message_id,
                        text, owner_id, static_cast<int>(speed));
} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to save inline message: id=" << inline_message_id << ", error=" << e.what();
    throw;
}

std::optional<MessageStorage::MessageInfo> MessageStorage::GetMessage(std::string_view inline_message_id) const try {
    const auto result =
        pg_cluster->Execute(userver::storages::postgres::ClusterHostType::kMaster, sql::kGetMessage, inline_message_id);
    if (result.IsEmpty()) {
        return std::nullopt;
    }
    const auto row = result.Front();
    return MessageStorage::MessageInfo{.text = row["message_text"].As<std::string>(),
                                       .owner_id = row["owner_id"].As<int64_t>(),
                                       .speed = static_cast<size_t>(row["speed"].As<int>())};

} catch (const std::exception& e) {
    LOG_ERROR() << "Failed to get message: id=" << inline_message_id << ", error=" << e.what();
    throw;
}

}  // namespace tg_bot
