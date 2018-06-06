#include "records.ih"

void Records::remove() const
{
    removeExistingNew();

    string request;                     // get the request
    d_arg.option(&request, 'r');

    uint64_t targetOffset;
    string targetKey;
    if (request.find('@') == string::npos)  // no e-mail, then offset
    {
        targetOffset = stoull(request);
        cout << "removing entry at offset " << targetOffset << '\n';
        request.clear();
    }
    else
    {
        targetOffset = 0;
        targetKey = Tools::md5hash(request);
        cout << "removing e-mail address " << request << '\n';
    }

    DataStore newStore{ d_arg[1] };         // new DataStore
    uint64_t offset = 0;
    while (true)
    {
                                            // process all entries
        DataIdx::Entry *ep = d_dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        Psych psych{ d_data };
        if (psych.get(ep->key))
        {
            if (ep->offset == targetOffset || ep->key == targetKey)
                continue;

            psych.put(newStore, ep->key);
        }
    }
}
