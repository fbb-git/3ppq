#include "client.ih"

void Client::pidCid(WIPdata const &wipData)
{
    d_display.append("pid", to_string(wipData.psychID()));
    d_display.append("cid", wipData.clientIdent());
}
