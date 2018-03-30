#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>

#include "service.h"

namespace restful {

service::service(const request_handler& handler)
    : m_handler(handler)
{
}

service::~service()
{
    beingDeleted();
}

void service::handleRequest(const request& request, response& response)
{
    m_handler(request, response);
}

}
