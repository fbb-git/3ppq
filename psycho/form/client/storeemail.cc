#include "client.ih"

void Client::storeEmail()
{
    WIPdata wipData{ d_cgi.param1("pid"), d_cgi.param1("cid") };

    LockGuard lg = wipData.read();

    if (wipData.hasEmail())
        throw Tools::DATA_AVAILABLE;

    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
    {
        wipData.setOtherEmail(idx, d_cgi.param1("e" + to_string(idx)));
        inviteOther(wipData, idx);
    }

    wipData.rmClientLogin();

    wipData.write();

    d_display.out("alldone.h");
}
