#include "records.ih"

void Records::expired() const
{
    string nDays;
    d_arg.option(&nDays, 'e');

    DateTime expirationTime(
                    time(0) - stoul(nDays) * 24 * 3600, DateTime::UTC 
                );

    std::vector<string> eMail;

    uint64_t offset = 0;
    while (true)
    {
        DataIdx::Entry *ep = d_dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        Psych psych{ d_data };

        if (psych.get(ep->key) and not psych.ack())
        {
            if (
                DateTime{ psych.registrationTime(), DateTime::UTC } <
                expirationTime
            )
                eMail.push_back(psych.eMail());
        }
    }

    DataStore dataStore{ d_data };

    Psych psych{ d_data };

    for (string const &mail: eMail)
    {
        string hash = Tools::md5hash(mail);         // hash the psych's e-mail
        
        if (not psych.get(hash))                    // get the psych's record
            g_log << mail << " not found" << endl;
        else if (psych.erase())
            g_log << "removed expired psychologist. E-mail: " << mail << endl;
        else
            g_log << 
                "could not auto-remove expired psychologist (email " << 
                mail << ": registration at " << 
                        DateTime{ psych.registrationTime(), DateTime::UTC } <<
                    ", expiration at " << expirationTime << ')' << endl;
    }
}




