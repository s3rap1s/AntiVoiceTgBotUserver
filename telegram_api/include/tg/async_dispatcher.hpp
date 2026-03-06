#pragma once

#include <algorithm>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <utility>
#include <vector>

#include <userver/engine/async.hpp>
#include <userver/engine/mutex.hpp>
#include <userver/engine/semaphore.hpp>
#include <userver/engine/task/task.hpp>
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
    struct Options final {
        std::size_t max_in_flight{1024};
        bool drop_on_overload{true};
        std::size_t collect_finished_every{64};
    };

    struct Stats final {
        std::uint64_t accepted{0};
        std::uint64_t dropped{0};
        std::uint64_t completed{0};
        std::uint64_t failed{0};
        std::uint64_t in_flight{0};
    };

    using UpdateHandler = std::function<void(AsyncDispatcherContext&)>;

    template <typename T>
    using EventHandler = std::function<void(AsyncDispatcherContext&, const T&)>;

    AsyncDispatcher(BotApi& api_ref, userver::engine::TaskProcessor& task_processor_ref)
        : AsyncDispatcher(api_ref, task_processor_ref, Options{}) {}

    AsyncDispatcher(BotApi& api_ref, userver::engine::TaskProcessor& task_processor_ref, Options options)
        : api(api_ref),
          task_processor(task_processor_ref),
          options(std::move(options)),
          in_flight_semaphore(this->options.max_in_flight == 0 ? 1 : this->options.max_in_flight) {
        if (this->options.max_in_flight == 0) this->options.max_in_flight = 1;
        if (this->options.collect_finished_every == 0) this->options.collect_finished_every = 1;
    }

    ~AsyncDispatcher() { CancelAll(); }

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
            [](const Update& update) -> const Optional<BusinessMessagesDeleted>& {
                return update.deleted_business_messages;
            },
            std::move(handler));
    }

    void OnMessageReaction(EventHandler<MessageReactionUpdated> handler) {
        AddOptionalRoute<MessageReactionUpdated>(
            [](const Update& update) -> const Optional<MessageReactionUpdated>& { return update.message_reaction; },
            std::move(handler));
    }

    void OnMessageReactionCount(EventHandler<MessageReactionCountUpdated> handler) {
        AddOptionalRoute<MessageReactionCountUpdated>(
            [](const Update& update) -> const Optional<MessageReactionCountUpdated>& {
                return update.message_reaction_count;
            },
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

    [[nodiscard]] bool Dispatch(Update update) {
        const auto n = dispatch_counter.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n % options.collect_finished_every == 0) CollectFinished();

        if (!AcquireSlot()) return false;

        accepted.fetch_add(1, std::memory_order_relaxed);
        in_flight.fetch_add(1, std::memory_order_relaxed);

        userver::engine::Task task;
        try {
            task = userver::engine::AsyncNoSpan(task_processor, [this, update = std::move(update)]() mutable {
            struct SlotGuard final {
                userver::engine::CancellableSemaphore& semaphore;
                std::atomic<std::uint64_t>& in_flight;
                ~SlotGuard() {
                    in_flight.fetch_sub(1, std::memory_order_relaxed);
                    semaphore.unlock_shared();
                }
            } slot_guard{in_flight_semaphore, in_flight};

                try {
                    AsyncDispatcherContext context{api, update};
                    for (const auto& route : routes) {
                        if (!route.match(update)) continue;
                        route.invoke(context);
                    }
                    completed.fetch_add(1, std::memory_order_relaxed);
                } catch (const std::exception& e) {
                    failed.fetch_add(1, std::memory_order_relaxed);
                    LOG_WARNING() << "Async dispatcher update failed: " << e.what();
                } catch (...) {
                    failed.fetch_add(1, std::memory_order_relaxed);
                    LOG_WARNING() << "Async dispatcher update failed: unknown exception";
                }
            });
        } catch (...) {
            in_flight.fetch_sub(1, std::memory_order_relaxed);
            in_flight_semaphore.unlock_shared();
            throw;
        }

        std::lock_guard lock(mutex);
        tasks.push_back(std::move(task));
        return true;
    }

    [[nodiscard]] Stats GetStats() const noexcept {
        return Stats{
            .accepted = accepted.load(std::memory_order_relaxed),
            .dropped = dropped.load(std::memory_order_relaxed),
            .completed = completed.load(std::memory_order_relaxed),
            .failed = failed.load(std::memory_order_relaxed),
            .in_flight = in_flight.load(std::memory_order_relaxed),
        };
    }

   private:
    struct Route {
        std::function<bool(const Update&)> match;
        UpdateHandler invoke;
    };

    template <typename T>
    using OptionalAccessor = std::function<const Optional<T>&(const Update&)>;

    template <typename T>
    using PointerAccessor = std::function<const std::unique_ptr<T, MessageDeleter>&(const Update&)>;

    template <typename T>
    void AddOptionalRoute(OptionalAccessor<T> accessor, EventHandler<T> handler) {
        AddRoute(Route{
            .match =
                [accessor](const Update& update) {
                    const auto& value = accessor(update);
                    return value.has_value();
                },
            .invoke = [accessor, handler = std::move(handler)](
                          AsyncDispatcherContext& context) { handler(context, *accessor(context.update)); },
        });
    }

    template <typename T>
    void AddPointerRoute(PointerAccessor<T> accessor, EventHandler<T> handler) {
        AddRoute(Route{
            .match = [accessor](const Update& update) {
                const auto& value = accessor(update);
                return static_cast<bool>(value);
            },
            .invoke = [accessor, handler = std::move(handler)](AsyncDispatcherContext& context) {
                handler(context, *accessor(context.update));
            },
        });
    }

    void AddRoute(Route route) { routes.push_back(std::move(route)); }

    [[nodiscard]] bool AcquireSlot() {
        if (options.drop_on_overload) {
            if (!in_flight_semaphore.try_lock_shared()) {
                dropped.fetch_add(1, std::memory_order_relaxed);
                return false;
            }
            return true;
        }

        try {
            in_flight_semaphore.lock_shared();
            return true;
        } catch (const userver::engine::SemaphoreLockCancelledError&) {
            dropped.fetch_add(1, std::memory_order_relaxed);
            return false;
        }
    }

    void CollectFinished() {
        std::lock_guard lock(mutex);
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [](auto& task) { return task.IsFinished(); }),
                    tasks.end());
    }

    void CancelAll() noexcept {
        std::vector<userver::engine::Task> local_tasks;
        {
            std::lock_guard lock(mutex);
            std::swap(local_tasks, tasks);
        }
        for (auto& task : local_tasks) task.RequestCancel();
    }

    BotApi& api;
    userver::engine::TaskProcessor& task_processor;
    Options options;
    userver::engine::CancellableSemaphore in_flight_semaphore;
    std::vector<Route> routes;
    mutable userver::engine::Mutex mutex;
    std::vector<userver::engine::Task> tasks;
    std::atomic<std::uint64_t> dispatch_counter{0};
    std::atomic<std::uint64_t> accepted{0};
    std::atomic<std::uint64_t> dropped{0};
    std::atomic<std::uint64_t> completed{0};
    std::atomic<std::uint64_t> failed{0};
    std::atomic<std::uint64_t> in_flight{0};
};

}  // namespace tg
