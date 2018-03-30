#ifndef RESTFUL_CPP_SERVER_H
#define RESTFUL_CPP_SERVER_H

#include <string>
#include <Wt/WServer.h>

namespace Wt {
    class WResource;
}

namespace restful {

class server: private Wt::WServer {
    typedef Wt::WServer base;
public:
    server(int argc, char** argv);

public:
    void register_service(Wt::WResource* service, const std::string& name);
    int start_and_wait_for_shutdown(); // blocking
};

}
#endif // RESTFUL_CPP_SERVER_H
