#include "mail.ih"

void Mail::checkEnvelope()
{
                                    // get the address in the 'From ' header
    string address1 = String::split(d_mh[0])[1].first;

    d_mh.setHeaderIterator("Received-SPF");

    string address2('\n', 1);       // won't match the psych-lines

    if (d_mh.beginh() != d_mh.endh())    
        address2 = *d_mh.beginh();      // get the SPF header

    ifstream psychStr{d_user.homedir() + s_psychologists};

    string psych;
    while (getline(psychStr, psych))
    {
        auto vect = String::split(psych, ",");

        string const &email = vect[1].first;

        if (address1 == email || address2.find(email) != string::npos)
        {
            d_psych = { vect[0].first, email, vect[2].first };
            return;
        }
    }
    throw 0;                        // unknown address
}
