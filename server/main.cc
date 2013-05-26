#include "server.h"
#include "client.h"
#include <iostream>
#include <msgpack/rpc/client.h>

int main(int argc, char **argv)
{
    ldb::LdbServer svr;
    svr.start();

    ldb::LdbClient client;
    client.create_table("blogs");
    return 0;
}
