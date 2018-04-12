#include "wip.ih"

void WIP::add(uint16_t psychID, uint16_t clientID, uint8_t login0)
{
    d_psychID = psychID;
    d_clientID = clientID;

    d_login[0] = login0;
    d_login[1] = Tools::random(10, 99);


    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
        d_login[2 + idx] = Tools::random(10, 99);

    memset(&d_data[0][0], 0, size(d_data));

    string data = toString();

    d_wipStream.open();
    LockGuard lg{ d_wipStream.lg() };
    d_wipStream.seekp(0, ios::end);

    uint16_t size = data.size();
    Tools::writeN(d_wipStream, &size);
    Tools::write(d_wipStream, data);
}
