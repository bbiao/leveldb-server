#ifndef LDB_SERVER_H
#define LDB_SERVER_H

#include <string>
#include <msgpack/rpc/server.h>

namespace ldb
{

typedef msgpack::rpc::dispatcher Dispatcher;
typedef msgpack::rpc::request Request;

class Server: public Dispatcher
{
public:
    void dispatch(Request req);

private:
    void _echo(Request req, const std::string& str);
};

}

#endif //LDB_SERVER_H
