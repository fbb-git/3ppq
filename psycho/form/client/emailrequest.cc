#include "client.ih"

void Client::emailRequest(WIPdata const &wipData)
{
    if (not wipData.otherEmail(0).empty())
        throw false;

    pidCid(wipData);
    d_display.out("emailrequest.h");
}
