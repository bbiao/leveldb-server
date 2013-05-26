#include "client.h"

namespace ldb
{

LdbClient::LdbClient()
{
    _client = new Client("127.0.0.1", 1985);
}

LdbClient::~LdbClient()
{
    delete _client;
}

bool LdbClient::create_table(const std::string& table_name)
{
    std::string res = _client->call("create table", table_name).get<std::string>();
    std::cout << res << std::endl;
    return true;
}

}
