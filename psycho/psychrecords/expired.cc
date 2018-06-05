#include "main.ih"

int expired(string const &data)
{
    DataIdx dataIdx(data + ".idx");

    uint64_t offset = 0;
    DateTime beforeYesterday{ time(0) - 2 * 24 * 3600, DateTime::UTC };

    std::vector<string> eMail;

    DataStore dataStore{ data };

    while (true)
    {
        DataIdx::Entry *ep = dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        cout << "Entry at offset " << ep->offset << endl;

        Psych psych{ data };
        psych.get(ep->key);

        DateTime registrationTime(psych.registrationTime(), 
                                    DateTime::UTC);

        if (not psych.ack() && registrationTime < beforeYesterday)
            eMail.push_back(psych.eMail());
    }

    Psych psych{ data };

    for (string const &addr: eMail)
    {
        string hash = Tools::md5hash(addr);  // hash the psych's e-mail
        
        if (not psych.get(hash))                    // get the psych's record
            g_log << addr << " not found\n";
        else if (dataStore.erase(hash))
            g_log << "removed " << addr << endl;
        else
            g_log << "could not auot-remove " << addr << endl;
    }
    return 0;
}




