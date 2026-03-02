#include <tg/types/inline_query_result.hpp>
#include <tg/types/inline_query_result_article.hpp>
#include <tg/types/inline_query_result_audio.hpp>
#include <tg/types/inline_query_result_cached_audio.hpp>
#include <tg/types/inline_query_result_cached_document.hpp>
#include <tg/types/inline_query_result_cached_gif.hpp>
#include <tg/types/inline_query_result_cached_mpeg_4_gif.hpp>
#include <tg/types/inline_query_result_cached_photo.hpp>
#include <tg/types/inline_query_result_cached_sticker.hpp>
#include <tg/types/inline_query_result_cached_video.hpp>
#include <tg/types/inline_query_result_cached_voice.hpp>
#include <tg/types/inline_query_result_contact.hpp>
#include <tg/types/inline_query_result_document.hpp>
#include <tg/types/inline_query_result_game.hpp>
#include <tg/types/inline_query_result_gif.hpp>
#include <tg/types/inline_query_result_location.hpp>
#include <tg/types/inline_query_result_mpeg_4_gif.hpp>
#include <tg/types/inline_query_result_photo.hpp>
#include <tg/types/inline_query_result_venue.hpp>
#include <tg/types/inline_query_result_video.hpp>
#include <tg/types/inline_query_result_voice.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResult Parse(const Value& value, To<InlineQueryResult>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "article") return ParseComplex<InlineQueryResultArticle>(value);
    if (type == "audio") {
        if (detail::IsPresent(value["audio_file_id"]))
            return ParseComplex<InlineQueryResultCachedAudio>(value);
        return ParseComplex<InlineQueryResultAudio>(value);
    }
    if (type == "document") {
        if (detail::IsPresent(value["document_file_id"]))
            return ParseComplex<InlineQueryResultCachedDocument>(value);
        return ParseComplex<InlineQueryResultDocument>(value);
    }
    if (type == "gif") {
        if (detail::IsPresent(value["gif_file_id"]))
            return ParseComplex<InlineQueryResultCachedGif>(value);
        return ParseComplex<InlineQueryResultGif>(value);
    }
    if (type == "mpeg4_gif") {
        if (detail::IsPresent(value["mpeg4_file_id"]))
            return ParseComplex<InlineQueryResultCachedMpeg4Gif>(value);
        return ParseComplex<InlineQueryResultMpeg4Gif>(value);
    }
    if (type == "photo") {
        if (detail::IsPresent(value["photo_file_id"]))
            return ParseComplex<InlineQueryResultCachedPhoto>(value);
        return ParseComplex<InlineQueryResultPhoto>(value);
    }
    if (type == "sticker")
        return ParseComplex<InlineQueryResultCachedSticker>(value);
    if (type == "video") {
        if (detail::IsPresent(value["video_file_id"]))
            return ParseComplex<InlineQueryResultCachedVideo>(value);
        return ParseComplex<InlineQueryResultVideo>(value);
    }
    if (type == "voice") {
        if (detail::IsPresent(value["voice_file_id"]))
            return ParseComplex<InlineQueryResultCachedVoice>(value);
        return ParseComplex<InlineQueryResultVoice>(value);
    }
    if (type == "contact") return ParseComplex<InlineQueryResultContact>(value);
    if (type == "game") return ParseComplex<InlineQueryResultGame>(value);
    if (type == "location")
        return ParseComplex<InlineQueryResultLocation>(value);
    if (type == "venue") return ParseComplex<InlineQueryResultVenue>(value);
    throw std::runtime_error("Unknown InlineQueryResult type: " + type);
}

}  // namespace tg
