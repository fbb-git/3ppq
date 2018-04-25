#include "client.ih"

bool Client::otherRatingsCompleted(WIPdata const &wipData) const
{
    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
    {
        if (wipData.otherRatings[idx].front() == 0)
            return false;
    }                    
    
    return true;                           
}
