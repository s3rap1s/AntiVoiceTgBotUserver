#include <userver/clients/dns/component.hpp>
#include <userver/clients/http/component_list.hpp>
#include <userver/components/component_list.hpp>
#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/ping.hpp>
#include <userver/utils/daemon_run.hpp>

#include "telegram/log_updates_component.hpp"

int main(int argc, char* argv[]) {
    auto components =
        userver::components::MinimalServerComponentList()
            .Append<userver::server::handlers::Ping>()
            .AppendComponentList(userver::clients::http::ComponentList())
            .Append<userver::clients::dns::Component>()
            .Append<tg_bot::TelegramBotComponent>();

    return userver::utils::DaemonMain(argc, argv, components);
}