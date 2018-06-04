#include "client.ih"

bool Client::otherRatingsCompleted(WIPdata &wipData) const
{
    if (g_config.findKeyTail("oneOther:") == "true")
    {
        g_log << wipData.pidCid() <<": only one other rating required" << 
                endl;

        for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
        {
            if (wipData.otherRatings(idx).front() != 0)
                return true;
        }
        return false;
    }

    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
    {
        if (wipData.otherRatings(idx).front() == 0)
            return false;
    }                    
    
    return true;                           
}
