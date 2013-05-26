#include "server.h"

namespace ldb
{

void Server::dispatch(Request req)
{
    std::string method;
    req.method().convert(&method);

    if (method == "echo") {
        msgpack::type::tuple<std::string> params;
        req.params().convert(&params);

        _echo(req, params.get<0>());
    } else {
        req.error(msgpack::rpc::NO_METHOD_ERROR);
    }
}

void Server::_echo(Request req, const std::string& str)
{
    req.result(str);
}

}
