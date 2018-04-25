#include "client.ih"

string Client::loginHash(uint16_t login) const
{
    return Tools::md5hashText(to_string(login));
}
