#include <types/animation.hpp>
#include <types/audio.hpp>
#include <types/chat.hpp>
#include <types/checklist.hpp>
#include <types/contact.hpp>
#include <types/dice.hpp>
#include <types/document.hpp>
#include <types/external_reply_info.hpp>
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
#include <types/video.hpp>
#include <types/video_note.hpp>
#include <types/voice.hpp>

#include "common.hpp"

namespace tg {

ExternalReplyInfo Parse(const Value& value, To<ExternalReplyInfo>) {
    ExternalReplyInfo obj{};
    obj.origin = ParseComplex<MessageOrigin>(value["origin"]);
    obj.chat = ParseComplex<Optional<Chat>>(value["chat"]);
    obj.message_id = ParseComplex<Optional<Integer>>(value["message_id"]);
    obj.link_preview_options = ParseComplex<Optional<LinkPreviewOptions>>(
        value["link_preview_options"]);
    obj.animation = ParseComplex<Optional<Animation>>(value["animation"]);
    obj.audio = ParseComplex<Optional<Audio>>(value["audio"]);
    obj.document = ParseComplex<Optional<Document>>(value["document"]);
    obj.paid_media = ParseComplex<Optional<PaidMediaInfo>>(value["paid_media"]);
    obj.photo = ParseComplex<Optional<Array<PhotoSize>>>(value["photo"]);
    obj.sticker = ParseComplex<Optional<Sticker>>(value["sticker"]);
    obj.story = ParseComplex<Optional<Story>>(value["story"]);
    obj.video = ParseComplex<Optional<Video>>(value["video"]);
    obj.video_note = ParseComplex<Optional<VideoNote>>(value["video_note"]);
    obj.voice = ParseComplex<Optional<Voice>>(value["voice"]);
    obj.has_media_spoiler =
        ParseComplex<OptionalTrue>(value["has_media_spoiler"]);
    obj.checklist = ParseComplex<Optional<Checklist>>(value["checklist"]);
    obj.contact = ParseComplex<Optional<Contact>>(value["contact"]);
    obj.dice = ParseComplex<Optional<Dice>>(value["dice"]);
    obj.game = ParseComplex<Optional<Game>>(value["game"]);
    obj.giveaway = ParseComplex<Optional<Giveaway>>(value["giveaway"]);
    obj.giveaway_winners =
        ParseComplex<Optional<GiveawayWinners>>(value["giveaway_winners"]);
    obj.invoice = ParseComplex<Optional<Invoice>>(value["invoice"]);
    obj.location = ParseComplex<Optional<Location>>(value["location"]);
    obj.poll = ParseComplex<Optional<Poll>>(value["poll"]);
    obj.venue = ParseComplex<Optional<Venue>>(value["venue"]);
    return obj;
}

}  // namespace tg
