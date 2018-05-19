#include "psych.ih"

void Psych::rmExistingWIPdata(PsychClient const &client, 
                              char const *txt) const
{
    if (WIPdata::exists(d_ID, client.ident()))
    {
        Tools::stdLog() << "wip data " << d_ID << '.' << client.ident() << 
                           " should not exist: " << txt << endl;
        WIPdata::remove(d_ID, client.ident());
    }
}
