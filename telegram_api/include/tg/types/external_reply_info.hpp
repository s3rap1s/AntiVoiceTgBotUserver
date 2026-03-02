#pragma once

#include <tg/types/animation.hpp>
#include <tg/types/audio.hpp>
#include <tg/types/chat.hpp>
#include <tg/types/checklist.hpp>
#include <tg/types/common.hpp>
#include <tg/types/contact.hpp>
#include <tg/types/dice.hpp>
#include <tg/types/document.hpp>
#include <tg/types/game.hpp>
#include <tg/types/giveaway.hpp>
#include <tg/types/giveaway_winners.hpp>
#include <tg/types/invoice.hpp>
#include <tg/types/link_preview_options.hpp>
#include <tg/types/location.hpp>
#include <tg/types/message_origin.hpp>
#include <tg/types/paid_media_info.hpp>
#include <tg/types/photo_size.hpp>
#include <tg/types/poll.hpp>
#include <tg/types/sticker.hpp>
#include <tg/types/story.hpp>
#include <tg/types/venue.hpp>
#include <tg/types/video_note.hpp>
#include <tg/types/voice.hpp>

namespace tg {

struct ExternalReplyInfo {
    MessageOrigin origin;
    Optional<Chat> chat;
    Optional<Integer> message_id;
    Optional<LinkPreviewOptions> link_preview_options;
    Optional<Animation> animation;
    Optional<Audio> audio;
    Optional<Document> document;
    Optional<PaidMediaInfo> paid_media;
    Optional<Array<PhotoSize>> photo;
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
