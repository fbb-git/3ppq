#include "main.ih"

int modify(string const &data, string const &destination)
{
    DataIdx dataIdx(data + ".idx");

    DataStore newStorage{ destination };

    uint64_t offset = 0;
    while (true)
    {
        DataIdx::Entry *ep = dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        cout << "Entry at offset " << ep->offset << endl;

        Psych psych{ data };
        psych.get(ep->key);
        psych.put(newStorage, ep->key);
    }

    return 0;
}
