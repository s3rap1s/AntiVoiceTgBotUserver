#pragma once

#include <types/animation.hpp>
#include <types/audio.hpp>
#include <types/chat.hpp>
#include <types/checklist.hpp>
#include <types/common.hpp>
#include <types/contact.hpp>
#include <types/dice.hpp>
#include <types/document.hpp>
#include <types/game.hpp>
#include <types/giveaway.hpp>
#include <types/giveaway_winners.hpp>
#include <types/invoice.hpp>
#include <types/link_preview_options.hpp>
#include <types/location.hpp>
#include <types/message_origin.hpp>
#include <types/paid_media_info.hpp>
#include <types/photo_size.hpp>
#include <types/poll.hpp>
#include <types/sticker.hpp>
#include <types/story.hpp>
#include <types/venue.hpp>
#include <types/video_note.hpp>
#include <types/voice.hpp>

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
