#include "wip.ih"

string WIP::toString() const
{
    ostringstream out;

    Tools::writeN(out, &d_psychID);
    Tools::writeN(out, &d_clientID);

    for (size_t idx = 0; idx != Tools::N_OTHER + 2; ++idx)  // login codes
        Tools::writeN(out, &d_login[idx]);

    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)      //  e-mail addr.
        out <<  d_email[idx] << '\n';

    Tools::write(out, &d_data[0][0], size(d_data));
    
    return out.str();
}
