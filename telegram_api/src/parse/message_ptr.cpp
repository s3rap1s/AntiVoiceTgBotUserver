#include <types/message.hpp>
#include <types/message_ptr.hpp>

namespace tg {

void MessageDeleter::operator()(Message* p) const noexcept { delete p; }

}  // namespace tg