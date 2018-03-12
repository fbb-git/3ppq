#include "mail.ih"

void Mail::uniquePreID(string const &preID)
{
    ifstream clientStr{ d_user.homedir() + s_clients };
    string const &psychID = d_psych[Psych::ID];

    string client;
    while (getline(clientStr, client))
    {
        auto vect = String::split(client, ",");

                                                    // ignore other psych.
                                                    // IDs
        if (vect[Clients::PSYCH_ID].first != psychID)
            continue;

        if (vect[Clients::PRE_ID].first == preID)
            throw Exception{} << "preID " << preID << " is not unique";
    }
        
}
