#pragma once

#include "animation.hpp"
#include "audio.hpp"
#include "chat.hpp"
#include "checklist.hpp"
#include "common.hpp"
#include "contact.hpp"
#include "dice.hpp"
#include "document.hpp"
#include "game.hpp"
#include "giveaway.hpp"
#include "giveaway_winners.hpp"
#include "invoice.hpp"
#include "link_preview_options.hpp"
#include "location.hpp"
#include "message_origin.hpp"
#include "paid_media_info.hpp"
#include "poll.hpp"
#include "sticker.hpp"
#include "story.hpp"
#include "venue.hpp"
#include "video_note.hpp"
#include "voice.hpp"

namespace tg {

struct ExternalReplyInfo {
    MessageOrigin origin;
    Optional<Chat> chat;
    Integer message_id;
    Optional<LinkPreviewOptions> link_preview_options;
    Optional<Animation> animation;
    Optional<Audio> audio;
    Optional<Document> document;
    Optional<PaidMediaInfo> paid_media;
    Optional<OneOf<PhotoSize>> photo;
    Optional<Sticker> sticker;
    Optional<Story> story;
    Optional<Video> video;
    Optional<VideoNote> video_note;
    Optional<Voice> voice;
    OptionalTrue has_media_spoiler;
    Optional<Checklist> checklist;
    Optional<Contact> contact;
    Optional<Dice> dice;
    Optional<Game> game;
    Optional<Giveaway> giveaway;
    Optional<GiveawayWinners> giveaway_winners;
    Optional<Invoice> invoice;
    Optional<Location> location;
    Optional<Poll> poll;
    Optional<Venue> venue;
};

ExternalReplyInfo Parse(const Value& value, To<ExternalReplyInfo>);

}  // namespace tg
