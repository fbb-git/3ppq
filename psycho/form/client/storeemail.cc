#include "client.ih"

void Client::storeEmail()
{
    WIPdata wipData{ d_cgi.param1("pid"), d_cgi.param1("cid") };

    LockGuard lg = wipData.read();

    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
    {
        if (not wipData.otherMail(idx).empty())
        {            
            d_display.homePage();
            return;
        }
    }

    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
    {
        wipData.setOtherMail(idx, d_cgi.param1("e" + to_string(idx)));
        inviteOther(wipData.otherMail(idx));
    }

    pidCid(wipData);
    d_display.out("emailok.h");
}
