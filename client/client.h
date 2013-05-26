#ifndef LDB_CLIENT_H
#define LDB_CLIENT_H

#include <string>
#include <msgpack/rpc/client.h>

namespace ldb
{

struct Result
{
    int err_no;
    int err_msg;

    MSGPACK_DEFINE(err_no, err_msg);
};

typedef msgpack::rpc::client Client;

class LdbClient
{
public:
    LdbClient();
    virtual ~LdbClient();

    bool create_table(const std::string& table_name);
private:
    Client* _client;
};

}

#endif //LDB_CLIENT_H
