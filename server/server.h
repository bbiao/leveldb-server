#ifndef LDB_SERVER_H
#define LDB_SERVER_H

#include <string>
#include <msgpack/rpc/server.h>

namespace ldb
{

typedef msgpack::rpc::dispatcher Dispatcher;
typedef msgpack::rpc::request Request;
typedef msgpack::rpc::server Server;

class LdbServer;

class LdbDispatcher: public Dispatcher
{
public:
    LdbDispatcher();
    virtual ~LdbDispatcher();

    void dispatch(Request req);
    void set_ldb_server(LdbServer* ldb_server) { _server = ldb_server; }
private:
    LdbServer* _server;
private:
    LdbDispatcher(const LdbDispatcher&);
    LdbDispatcher& operator=(const LdbDispatcher&);
};

class LdbServer
{
public:
    LdbServer();
    virtual ~LdbServer();

    void start();
    void create_table(Request req, const std::string& table_name);
private:
    Server* _server;
    LdbDispatcher* _dispatcher;

private:
    LdbServer(const LdbServer&);
    LdbServer& operator=(const LdbServer&);
};

}

#endif //LDB_SERVER_H
