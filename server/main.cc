#include "server.h"
#include <iostream>
#include <msgpack/rpc/client.h>

int main(int argc, char **argv)
{
    std::auto_ptr<ldb::Dispatcher> dispatcher(new ldb::Server);
    msgpack::rpc::server svr;
    svr.serve(dispatcher.get());
    svr.listen("0.0.0.0", 1985);
    svr.start(4);

    msgpack::rpc::client c("127.0.0.1", 1985);

    std::string res = c.call("echo", std::string("hello")).get<std::string>();
    std::cout << res << std::endl;

    return 0;
}
