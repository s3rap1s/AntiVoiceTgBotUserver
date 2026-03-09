#include "components/tg_bot_component.hpp"

#include <userver/clients/dns/component.hpp>
#include <userver/clients/http/component_list.hpp>
#include <userver/components/component_list.hpp>
#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/ping.hpp>
#include <userver/storages/postgres/component.hpp>
#include <userver/testsuite/testsuite_support.hpp>
#include <userver/utils/daemon_run.hpp>

int main(int argc, char* argv[]) {
    auto components = userver::components::MinimalServerComponentList()
                          .Append<userver::server::handlers::Ping>()
                          .Append<userver::components::TestsuiteSupport>()
                          .AppendComponentList(userver::clients::http::ComponentList())
                          .Append<userver::clients::dns::Component>()
                          .Append<userver::components::Postgres>("postgres-db-1")
                          .Append<tg_bot::TelegramBotComponent>();

    return userver::utils::DaemonMain(argc, argv, components);
}
