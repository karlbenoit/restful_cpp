#include <Wt/WResource.h>

#include "server.h"

namespace restful {

server::server(int argc, char** argv): Wt::WServer()
{
    setServerConfiguration(argc, argv);
}

void server::register_service(Wt::WResource* service, const std::string& name)
{
    addResource(service, name);
}

int server::start_and_wait_for_shutdown()
{
    int sig = 0;

    if (start()) {
        sig = Wt::WServer::waitForShutdown();
        stop();
    }

    return sig;
}

}
