#pragma once

#include "common.hpp"
#include "inline_query_result_article.hpp"
#include "inline_query_result_audio.hpp"
#include "inline_query_result_cached_audio.hpp"
#include "inline_query_result_cached_document.hpp"
#include "inline_query_result_cached_gif.hpp"
#include "inline_query_result_cached_mpeg_4_gif.hpp"
#include "inline_query_result_cached_photo.hpp"
#include "inline_query_result_cached_sticker.hpp"
#include "inline_query_result_cached_video.hpp"
#include "inline_query_result_cached_voice.hpp"
#include "inline_query_result_contact.hpp"
#include "inline_query_result_document.hpp"
#include "inline_query_result_game.hpp"
#include "inline_query_result_gif.hpp"
#include "inline_query_result_location.hpp"
#include "inline_query_result_mpeg_4_gif.hpp"
#include "inline_query_result_photo.hpp"
#include "inline_query_result_venue.hpp"
#include "inline_query_result_video.hpp"
#include "inline_query_result_voice.hpp"

namespace tg {

using InlineQueryResult =
    OneOf<InlineQueryResultCachedAudio, InlineQueryResultCachedDocument,
          InlineQueryResultCachedGif, InlineQueryResultCachedMpeg4Gif,
          InlineQueryResultCachedPhoto, InlineQueryResultCachedSticker,
          InlineQueryResultCachedVideo, InlineQueryResultCachedVoice,
          InlineQueryResultArticle, InlineQueryResultAudio,
          InlineQueryResultContact, InlineQueryResultGame,
          InlineQueryResultDocument, InlineQueryResultGif,
          InlineQueryResultLocation, InlineQueryResultMpeg4Gif,
          InlineQueryResultPhoto, InlineQueryResultVenue,
          InlineQueryResultVideo, InlineQueryResultVoice>;

InlineQueryResult Parse(const Value& value, To<InlineQueryResult>);

}  // namespace tg
