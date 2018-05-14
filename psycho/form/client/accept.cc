#include "client.ih"

void Client::accept(string const &query)
{
g_log << "Client accept: " << query << endl;

    WIPdata wipData(query);

    LockGuard lg = wipData.read();      // if reading fails, throws an
                                        // error-enum value

    string hash = query.substr(query.find('=') + 1);
    if (hash.length() != Tools::HASH_TXT_SIZE)
        throw Tools::NO_QUERY;

    if (hash == loginHash(wipData.clientLogin()))   // self/meta ratings use
    {
        clientPage(wipData);                        // identical hashes
        return;
    }
g_log << "hash = " << hash << endl;
                                                        // otherwise activate
    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)  // an 'other' rater
    {
g_log << "Idx: " << idx << ", otherlogin: " << wipData.otherLogin(idx) << 
", hash: " << loginHash(wipData.otherLogin(idx)) << endl;

        if (hash == loginHash(wipData.otherLogin(idx)))
        {
g_log << "BINGO!" << endl;

            otherPage(wipData, idx);
            return;
        }
    }

    throw Tools::NO_QUERY;
}
