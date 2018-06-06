#include "records.ih"

void Records::modify() const
{
    removeExistingNew();

    DataStore newStore{ d_arg[1] };

    uint64_t offset = 0;
    while (true)
    {
        DataIdx::Entry *ep = d_dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        Psych psych{ d_data };

        if (psych.get(ep->key))
            psych.put(newStore, ep->key);
    }
}
