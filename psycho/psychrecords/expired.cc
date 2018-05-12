#include "main.ih"

void expired()
{
    DataIdx dataIdx(g_options.psych() + ".idx");

    uint64_t offset = 0;
    DateTime beforeYesterday{ time(0) - 2 * 24 * 3600, DateTime::UTC };

    std::vector<string> eMail;

    DataStore dataStore{ g_options.psych() };
    LockGuard lg{ dataStore.lg() };

    while (true)
    {
        DataIdx::Entry *ep = dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        cout << "Entry at offset " << ep->offset << endl;

        Psych psych;
        psych.get(ep->key);

        DateTime registrationTime(psych.registrationTime(), 
                                    DateTime::UTC);

        if (not psych.ack() && registrationTime < beforeYesterday)
            eMail.push_back(psych.eMail());
    }

    Psych psych;

    for (string const &addr: eMail)
    {
        string hash = Tools::md5hash(addr);  // hash the psych's e-mail
        
        if (not psych.get(hash))                    // get the psych's record
            g_log << addr << " not found\n";
        else
        {
            g_log << "removed " << addr << endl;
        }
    }
}




