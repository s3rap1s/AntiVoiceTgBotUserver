#pragma once

#include <atomic>
#include <functional>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>

#include <userver/concurrent/background_task_storage.hpp>
#include <userver/engine/mutex.hpp>
#include <userver/engine/task/task_processor_fwd.hpp>
#include <userver/logging/log.hpp>

#include <tg/bot_api.hpp>

namespace tg {

class AsyncDispatcherContext final {
   public:
    AsyncDispatcherContext(BotApi& api_ref, const Update& update_ref) : api(api_ref), update(update_ref) {}

    BotApi& api;
    const Update& update;
};

class AsyncDispatcher final {
   public:
    using UpdateHandler = std::function<void(AsyncDispatcherContext&)>;

    template <typename T>
    using EventHandler = std::function<void(AsyncDispatcherContext&, const T&)>;

    AsyncDispatcher(BotApi& api_ref, userver::engine::TaskProcessor& task_processor_ref)
        : state(std::make_shared<State>(api_ref, task_processor_ref)) {}

    ~AsyncDispatcher() { Stop(); }

    AsyncDispatcher(const AsyncDispatcher&) = delete;
    AsyncDispatcher& operator=(const AsyncDispatcher&) = delete;
    AsyncDispatcher(AsyncDispatcher&&) noexcept = default;
    AsyncDispatcher& operator=(AsyncDispatcher&&) noexcept = default;

    void OnUpdate(UpdateHandler handler) {
        AddRoute(Route{
            .match = [](const Update&) { return true; },
            .invoke = std::move(handler),
        });
    }

    void OnMessage(EventHandler<Message> handler) {
        AddOptionalRoute<Message>([](const Update& update) -> const Optional<Message>& { return update.message; },
                                  std::move(handler));
    }

    void OnEditedMessage(EventHandler<Message> handler) {
        AddOptionalRoute<Message>(
            [](const Update& update) -> const Optional<Message>& { return update.edited_message; }, std::move(handler));
    }

    void OnChannelPost(EventHandler<Message> handler) {
        AddOptionalRoute<Message>([](const Update& update) -> const Optional<Message>& { return update.channel_post; },
                                  std::move(handler));
    }

    void OnEditedChannelPost(EventHandler<Message> handler) {
        AddOptionalRoute<Message>(
            [](const Update& update) -> const Optional<Message>& { return update.edited_channel_post; },
            std::move(handler));
    }

    void OnBusinessConnection(EventHandler<BusinessConnection> handler) {
        AddOptionalRoute<BusinessConnection>(
            [](const Update& update) -> const Optional<BusinessConnection>& { return update.business_connection; },
            std::move(handler));
    }

    void OnBusinessMessage(EventHandler<Message> handler) {
        AddOptionalRoute<Message>(
            [](const Update& update) -> const Optional<Message>& { return update.business_message; },
            std::move(handler));
    }

    void OnEditedBusinessMessage(EventHandler<Message> handler) {
        AddOptionalRoute<Message>(
            [](const Update& update) -> const Optional<Message>& { return update.edited_business_message; },
            std::move(handler));
    }

    void OnDeletedBusinessMessages(EventHandler<BusinessMessagesDeleted> handler) {
        AddOptionalRoute<BusinessMessagesDeleted>(
            [](const Update& update) -> const Optional<BusinessMessagesDeleted>& { return update.deleted_business_messages; },
            std::move(handler));
    }

    void OnMessageReaction(EventHandler<MessageReactionUpdated> handler) {
        AddOptionalRoute<MessageReactionUpdated>(
            [](const Update& update) -> const Optional<MessageReactionUpdated>& { return update.message_reaction; },
            std::move(handler));
    }

    void OnMessageReactionCount(EventHandler<MessageReactionCountUpdated> handler) {
        AddOptionalRoute<MessageReactionCountUpdated>(
            [](const Update& update) -> const Optional<MessageReactionCountUpdated>& { return update.message_reaction_count; },
            std::move(handler));
    }

    void OnInlineQuery(EventHandler<InlineQuery> handler) {
        AddOptionalRoute<InlineQuery>(
            [](const Update& update) -> const Optional<InlineQuery>& { return update.inline_query; },
            std::move(handler));
    }

    void OnChosenInlineResult(EventHandler<ChosenInlineResult> handler) {
        AddOptionalRoute<ChosenInlineResult>(
            [](const Update& update) -> const Optional<ChosenInlineResult>& { return update.chosen_inline_result; },
            std::move(handler));
    }

    void OnCallbackQuery(EventHandler<CallbackQuery> handler) {
        AddOptionalRoute<CallbackQuery>(
            [](const Update& update) -> const Optional<CallbackQuery>& { return update.callback_query; },
            std::move(handler));
    }

    void OnShippingQuery(EventHandler<ShippingQuery> handler) {
        AddOptionalRoute<ShippingQuery>(
            [](const Update& update) -> const Optional<ShippingQuery>& { return update.shipping_query; },
            std::move(handler));
    }

    void OnPreCheckoutQuery(EventHandler<PreCheckoutQuery> handler) {
        AddOptionalRoute<PreCheckoutQuery>(
            [](const Update& update) -> const Optional<PreCheckoutQuery>& { return update.pre_checkout_query; },
            std::move(handler));
    }

    void OnPurchasedPaidMedia(EventHandler<PaidMediaPurchased> handler) {
        AddOptionalRoute<PaidMediaPurchased>(
            [](const Update& update) -> const Optional<PaidMediaPurchased>& { return update.purchased_paid_media; },
            std::move(handler));
    }

    void OnPoll(EventHandler<Poll> handler) {
        AddOptionalRoute<Poll>([](const Update& update) -> const Optional<Poll>& { return update.poll; },
                               std::move(handler));
    }

    void OnPollAnswer(EventHandler<PollAnswer> handler) {
        AddOptionalRoute<PollAnswer>(
            [](const Update& update) -> const Optional<PollAnswer>& { return update.poll_answer; }, std::move(handler));
    }

    void OnMyChatMember(EventHandler<ChatMemberUpdated> handler) {
        AddOptionalRoute<ChatMemberUpdated>(
            [](const Update& update) -> const Optional<ChatMemberUpdated>& { return update.my_chat_member; },
            std::move(handler));
    }

    void OnChatMember(EventHandler<ChatMemberUpdated> handler) {
        AddOptionalRoute<ChatMemberUpdated>(
            [](const Update& update) -> const Optional<ChatMemberUpdated>& { return update.chat_member; },
            std::move(handler));
    }

    void OnChatJoinRequest(EventHandler<ChatJoinRequest> handler) {
        AddOptionalRoute<ChatJoinRequest>(
            [](const Update& update) -> const Optional<ChatJoinRequest>& { return update.chat_join_request; },
            std::move(handler));
    }

    void OnChatBoost(EventHandler<ChatBoostUpdated> handler) {
        AddOptionalRoute<ChatBoostUpdated>(
            [](const Update& update) -> const Optional<ChatBoostUpdated>& { return update.chat_boost; },
            std::move(handler));
    }

    void OnRemovedChatBoost(EventHandler<ChatBoostRemoved> handler) {
        AddOptionalRoute<ChatBoostRemoved>(
            [](const Update& update) -> const Optional<ChatBoostRemoved>& { return update.removed_chat_boost; },
            std::move(handler));
    }

    bool Dispatch(Update update) {
        const auto st = state;
        if (!st || !st->is_running.load(std::memory_order_acquire)) return false;

        std::vector<Route> routes_snapshot;
        {
            std::lock_guard lock(st->routes_mutex);
            routes_snapshot = st->routes;
        }

        st->tasks.AsyncDetach("tg-update-dispatch",
                              [st, update = std::move(update), routes = std::move(routes_snapshot)]() mutable {
                try {
                    AsyncDispatcherContext context{st->api, update};
                    for (const auto& route : routes) {
                        if (!route.match(update)) continue;
                        route.invoke(context);
                    }
                } catch (const std::exception& e) {
                    LOG_ERROR() << "Async dispatcher update failed: " << e.what();
                } catch (...) {
                    LOG_ERROR() << "Async dispatcher update failed: unknown exception";
                }
                              });

        return true;
    }

    void Start() {
        const auto st = state;
        if (!st) return;
        st->is_running.store(true, std::memory_order_release);
    }

    void Stop() noexcept {
        const auto st = state;
        if (!st) return;

        if (st->stop_started.exchange(true, std::memory_order_acq_rel)) return;
        st->is_running.store(false, std::memory_order_release);
        st->tasks.CancelAndWait();
    }

   private:
    struct Route final {
        std::function<bool(const Update&)> match;
        UpdateHandler invoke;
    };

    template <typename T>
    using OptionalAccessor = std::function<const Optional<T>&(const Update&)>;

    struct State final {
        State(BotApi& api_ref, userver::engine::TaskProcessor& task_processor_ref)
            : api(api_ref), tasks(task_processor_ref) {}

        BotApi& api;
        userver::concurrent::BackgroundTaskStorage tasks;

        mutable userver::engine::Mutex routes_mutex;
        std::vector<Route> routes;

        std::atomic<bool> is_running{true};
        std::atomic<bool> stop_started{false};
    };

    void AddRoute(Route route) {
        const auto st = state;
        if (!st) return;

        std::lock_guard lock(st->routes_mutex);
        st->routes.push_back(std::move(route));
    }

    template <typename T>
    void AddOptionalRoute(OptionalAccessor<T> accessor, EventHandler<T> handler) {
        AddRoute(Route{
            .match =
                [accessor](const Update& update) {
                    const auto& value = accessor(update);
                    return value.has_value();
                },
            .invoke = [accessor, handler = std::move(handler)](AsyncDispatcherContext& context) {
                handler(context, *accessor(context.update));
            },
        });
    }

    std::shared_ptr<State> state;
};

}  // namespace tg
