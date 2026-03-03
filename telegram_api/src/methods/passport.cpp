#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Boolean BotApi::SetPassportDataErrors(Integer user_id, Array<PassportElementError> errors) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "errors", errors);

    const auto result = client->CallResult("setPassportDataErrors", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
