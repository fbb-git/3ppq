#include "client.ih"

bool Client::accept(string const &query)
try
{
g_log << "Client accept: " << query << endl;

    WIPdata wipData(query);

    LockGuard lg = wipData.read();
    
    string hash = query.substr(query.find('=') + 1);

    if (hash == Tools::md5hashText(to_string(wipData.clientLogin())))
        return clientPage(wipData);

    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
    {
        if (hash == Tools::md5hashText(to_string(wipData.otherLogin(idx))))
            return otherPage(wipData, idx);
    }

    return false;
}
catch (...)
{
    return false;
}
