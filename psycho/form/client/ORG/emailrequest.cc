#include "client.ih"

void Client::emailRequest(WIPdata const &wipData)
{
    pidCid(wipData);
    d_display.out("emailrequest.h");
}
