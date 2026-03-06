#include <tg/types/business_connection.hpp>
#include <tg/types/business_messages_deleted.hpp>
#include <tg/types/chat_boost_removed.hpp>
#include <tg/types/chat_boost_updated.hpp>
#include <tg/types/chat_join_request.hpp>
#include <tg/types/chat_member_updated.hpp>
#include <tg/types/callback_query.hpp>
#include <tg/types/chosen_inline_result.hpp>
#include <tg/types/inline_query.hpp>
#include <tg/types/message.hpp>
#include <tg/types/message_reaction_count_updated.hpp>
#include <tg/types/message_reaction_updated.hpp>
#include <tg/types/paid_media_purchased.hpp>
#include <tg/types/poll.hpp>
#include <tg/types/poll_answer.hpp>
#include <tg/types/pre_checkout_query.hpp>
#include <tg/types/shipping_query.hpp>
#include <tg/types/update.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Update Parse(const Value& value, To<Update>) {
    Update obj{};
    obj.update_id = ParseComplex<Integer>(value["update_id"]);
    obj.message = ParseComplex<Optional<Message>>(value["message"]);
    obj.edited_message = ParseComplex<Optional<Message>>(value["edited_message"]);
    obj.channel_post = ParseComplex<Optional<Message>>(value["channel_post"]);
    obj.edited_channel_post = ParseComplex<Optional<Message>>(value["edited_channel_post"]);
    obj.business_connection = ParseComplex<Optional<BusinessConnection>>(value["business_connection"]);
    obj.business_message = ParseComplex<Optional<Message>>(value["business_message"]);
    obj.edited_business_message = ParseComplex<Optional<Message>>(value["edited_business_message"]);
    obj.deleted_business_messages = ParseComplex<Optional<BusinessMessagesDeleted>>(value["deleted_business_messages"]);
    obj.message_reaction = ParseComplex<Optional<MessageReactionUpdated>>(value["message_reaction"]);
    obj.message_reaction_count = ParseComplex<Optional<MessageReactionCountUpdated>>(value["message_reaction_count"]);
    obj.inline_query = ParseComplex<Optional<InlineQuery>>(value["inline_query"]);
    obj.chosen_inline_result = ParseComplex<Optional<ChosenInlineResult>>(value["chosen_inline_result"]);
    obj.callback_query = ParseComplex<Optional<CallbackQuery>>(value["callback_query"]);
    obj.shipping_query = ParseComplex<Optional<ShippingQuery>>(value["shipping_query"]);
    obj.pre_checkout_query = ParseComplex<Optional<PreCheckoutQuery>>(value["pre_checkout_query"]);
    obj.purchased_paid_media = ParseComplex<Optional<PaidMediaPurchased>>(value["purchased_paid_media"]);
    obj.poll = ParseComplex<Optional<Poll>>(value["poll"]);
    obj.poll_answer = ParseComplex<Optional<PollAnswer>>(value["poll_answer"]);
    obj.my_chat_member = ParseComplex<Optional<ChatMemberUpdated>>(value["my_chat_member"]);
    obj.chat_member = ParseComplex<Optional<ChatMemberUpdated>>(value["chat_member"]);
    obj.chat_join_request = ParseComplex<Optional<ChatJoinRequest>>(value["chat_join_request"]);
    obj.chat_boost = ParseComplex<Optional<ChatBoostUpdated>>(value["chat_boost"]);
    obj.removed_chat_boost = ParseComplex<Optional<ChatBoostRemoved>>(value["removed_chat_boost"]);
    return obj;
}

void Serialize(const Update& obj, ValueBuilder& builder) {
    internal::Put(builder, "update_id", obj.update_id);
    internal::Put(builder, "message", obj.message);
    internal::Put(builder, "edited_message", obj.edited_message);
    internal::Put(builder, "channel_post", obj.channel_post);
    internal::Put(builder, "edited_channel_post", obj.edited_channel_post);
    internal::Put(builder, "business_connection", obj.business_connection);
    internal::Put(builder, "business_message", obj.business_message);
    internal::Put(builder, "edited_business_message", obj.edited_business_message);
    internal::Put(builder, "deleted_business_messages", obj.deleted_business_messages);
    internal::Put(builder, "message_reaction", obj.message_reaction);
    internal::Put(builder, "message_reaction_count", obj.message_reaction_count);
    internal::Put(builder, "inline_query", obj.inline_query);
    internal::Put(builder, "chosen_inline_result", obj.chosen_inline_result);
    internal::Put(builder, "callback_query", obj.callback_query);
    internal::Put(builder, "shipping_query", obj.shipping_query);
    internal::Put(builder, "pre_checkout_query", obj.pre_checkout_query);
    internal::Put(builder, "purchased_paid_media", obj.purchased_paid_media);
    internal::Put(builder, "poll", obj.poll);
    internal::Put(builder, "poll_answer", obj.poll_answer);
    internal::Put(builder, "my_chat_member", obj.my_chat_member);
    internal::Put(builder, "chat_member", obj.chat_member);
    internal::Put(builder, "chat_join_request", obj.chat_join_request);
    internal::Put(builder, "chat_boost", obj.chat_boost);
    internal::Put(builder, "removed_chat_boost", obj.removed_chat_boost);
}

}  // namespace tg
