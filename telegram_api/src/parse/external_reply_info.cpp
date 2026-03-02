#include <tg/types/animation.hpp>
#include <tg/types/audio.hpp>
#include <tg/types/chat.hpp>
#include <tg/types/checklist.hpp>
#include <tg/types/contact.hpp>
#include <tg/types/dice.hpp>
#include <tg/types/document.hpp>
#include <tg/types/external_reply_info.hpp>
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
#include <tg/types/video.hpp>
#include <tg/types/video_note.hpp>
#include <tg/types/voice.hpp>

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
