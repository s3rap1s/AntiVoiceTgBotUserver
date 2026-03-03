#include <tg/types/chat_boost_source.hpp>
#include <tg/types/chat_boost_source_gift_code.hpp>
#include <tg/types/chat_boost_source_giveaway.hpp>
#include <tg/types/chat_boost_source_premium.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatBoostSource Parse(const Value& value, To<ChatBoostSource>) {
    const auto source = ParseComplex<String>(value["source"]);
    if (source == "premium") return ParseComplex<ChatBoostSourcePremium>(value);
    if (source == "gift_code") return ParseComplex<ChatBoostSourceGiftCode>(value);
    if (source == "giveaway") return ParseComplex<ChatBoostSourceGiveaway>(value);
    throw std::runtime_error("Unknown ChatBoostSource source: " + source);
}

void Serialize(const ChatBoostSource& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
