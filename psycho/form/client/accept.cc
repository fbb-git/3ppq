#include "client.ih"

void Client::accept(string const &query)
{
g_log << "Client accept: " << query << endl;

    WIPdata wipData(query);

    LockGuard lg = wipData.read();      // if reading fails, throw false,
                                        // results in showing /index.html
    
    string hash = query.substr(query.find('=') + 1);
    if (hash.length() != Tools::HASH_TXT_SIZE)
        throw false;

    if (hash == loginHash(wipData.clientLogin()))   // self/meta ratings use
    {
        clientPage(wipData);                        // identical hashes
        return;
    }

                                                        // otherwise activate
    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)  // an 'other' rater
    {
        if (hash == loginHash(wipData.otherLogin(idx)))
        {
            otherPage(wipData, idx);
            return;
        }
    }

    throw false;
}
