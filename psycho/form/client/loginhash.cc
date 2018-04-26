#include "client.ih"

string Client::loginHash(uint16_t login) const
{
    return login == 0 ? ""s : Tools::md5hashText(to_string(login));
}
