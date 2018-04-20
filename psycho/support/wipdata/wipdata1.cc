#include "wipdata.ih"

WIPdata::WIPdata(uint16_t psychID, uint16_t clientID, uint16_t login0)
:
    d_psychID(psychID),
    d_clientID(clientID),
    d_start(time(0)),
    d_login0(login0),
    d_loginClient(Tools::random(10, 99)),
    d_loginOther1(Tools::random(10, 99)),
    d_loginOther2(Tools::random(10, 99)),
    d_loginOther3(Tools::random(10, 99))
{}
