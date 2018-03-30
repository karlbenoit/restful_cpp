#ifndef RESTFUL_CPP_SERVICE_H
#define RESTFUL_CPP_SERVICE_H

#include <functional>
#include <Wt/WResource.h>
#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>

namespace restful {

using request = Wt::Http::Request;
using response = Wt::Http::Response;
using request_handler = std::function<void(const request&, response&)>;

class service: public Wt::WResource {
public:
    service(const request_handler& handler);
    virtual ~service();

public:
     void handleRequest(const request& request, response& response) override;

private:
    request_handler m_handler;
};

}

#endif

