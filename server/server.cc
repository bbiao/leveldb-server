#include "server.h"

namespace ldb
{

LdbDispatcher::LdbDispatcher(): _server(NULL)
{

}

LdbDispatcher::~LdbDispatcher()
{

}

void LdbDispatcher::dispatch(Request req)
{
    std::string method;
    req.method().convert(&method);

    if (method == "create table") {
        msgpack::type::tuple<std::string> params;
        req.params().convert(&params);

        _server->create_table(req, params.get<0>());
    } else {
        req.error(msgpack::rpc::NO_METHOD_ERROR);
    }
}

LdbServer::LdbServer()
{
    _dispatcher = new LdbDispatcher;
    _dispatcher->set_ldb_server(this);

    _server = new Server;
    _server->serve(_dispatcher);
}

LdbServer::~LdbServer()
{
    delete _dispatcher;
    delete _server;
}

void LdbServer::start()
{
    _server->listen("0.0.0.0", 1985);
    _server->start(4);
}

void LdbServer::create_table(Request req, const std::string& table_name)
{
    req.result(std::string("OK"));
}

}
