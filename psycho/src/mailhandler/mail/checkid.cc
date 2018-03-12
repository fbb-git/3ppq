#include "mail.ih"

void Mail::checkID()
{
    d_mh.setHeaderIterator("Subject");

    if (d_mh.beginh() == d_mh.endh())   // no Subject:
        throw 0;                        // so ignore.

                                        // get the received ID
    string id = String::split(*d_mh.beginh())[1].first;
    
    if (id != d_psych[Psych::ID])       // ignore the mail.
        throw 0;
}
