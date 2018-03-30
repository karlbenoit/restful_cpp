#include <iostream>
#include <server.h>
#include <service.h>

int main(int argc, char **argv)
{
    restful::server srv(argc, argv);
    restful::service service([](const restful::request&, restful::response& response){
        response.setMimeType("application/json");
        response.out() << "{\"status\" : \"ok\"}";
    });
    srv.register_service(&service, "/api");

    try {
        int signal = srv.start_and_wait_for_shutdown();
        std::cout << "exiting with signal " << signal << std::endl;
    } catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}
