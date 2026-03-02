#pragma once

#include <tg/types/business_connection.hpp>
#include <tg/types/business_messages_deleted.hpp>
#include <tg/types/chat_boost_removed.hpp>
#include <tg/types/chat_boost_updated.hpp>
#include <tg/types/chat_join_request.hpp>
#include <tg/types/chat_member_updated.hpp>
#include <tg/types/chosen_inline_result.hpp>
#include <tg/types/common.hpp>
#include <tg/types/inline_query.hpp>
#include <tg/types/message.hpp>
#include <tg/types/message_reaction_count_updated.hpp>
#include <tg/types/message_reaction_updated.hpp>
#include <tg/types/paid_media_purchased.hpp>
#include <tg/types/poll.hpp>
#include <tg/types/poll_answer.hpp>
#include <tg/types/pre_checkout_query.hpp>
#include <tg/types/shipping_query.hpp>

namespace tg {

struct Update {
    Integer update_id;
    Optional<Message> message;
    Optional<Message> edited_message;
    Optional<Message> channel_post;
    Optional<Message> edited_channel_post;
    Optional<BusinessConnection> business_connection;
    Optional<Message> business_message;
    Optional<Message> edited_business_message;
    Optional<BusinessMessagesDeleted> deleted_business_messages;
    Optional<MessageReactionUpdated> message_reaction;
    Optional<MessageReactionCountUpdated> message_reaction_count;
    Optional<InlineQuery> inline_query;
    Optional<ChosenInlineResult> chosen_inline_result;
    Optional<ShippingQuery> shipping_query;
    Optional<PreCheckoutQuery> pre_checkout_query;
    Optional<PaidMediaPurchased> purchased_paid_media;
    Optional<Poll> poll;
    Optional<PollAnswer> poll_answer;
    Optional<ChatMemberUpdated> my_chat_member;
    Optional<ChatMemberUpdated> chat_member;
    Optional<ChatJoinRequest> chat_join_request;
    Optional<ChatBoostUpdated> chat_boost;
    Optional<ChatBoostRemoved> removed_chat_boost;
};

Update Parse(const Value& value, To<Update>);

}  // namespace tg
