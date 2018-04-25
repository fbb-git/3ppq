#include "client.ih"

void Client::obtainEmail(WIPdata const &wipData)
{
    if (not wipData.otherEmail(0).empty())
        throw false;

    pidCid(wipData)
    d_display.out("reqemail.h");
}
