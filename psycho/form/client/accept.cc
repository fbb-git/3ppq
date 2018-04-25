#include "client.ih"

bool Client::accept(string const &query)
try
{
g_log << "Client accept: " << query << endl;

    WIPdata wipData(query);

    LockGuard lg = wipData.read();      // if reading fails, show /index.html
    
    string hash = query.substr(query.find('=') + 1);

    if (hash == loginHash(wipData.clientLogin()))   // self/meta ratings use
        return clientPage(wipData);                 // identical hashes

                                                        // otherwise activate
    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)  // an 'other' rater
    {
        if (hash == loginHash(wipData.otherLogin(idx)))
            return otherPage(wipData, idx);
    }

    return false;
}
catch (...)
{
    return false;
}
