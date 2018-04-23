#include "wipdata.ih"

string WIPdata::path() const
{
    return g_options.dataDir() + to_string(d_psychID) + '.' + 
                                 to_string(d_clientID);
}
