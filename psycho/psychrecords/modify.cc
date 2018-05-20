#include "main.ih"

void modify(char const *destination)
{
    DataIdx dataIdx(g_options.psych() + ".idx");

    DataStore newStorage{ destination };

    uint64_t offset = 0;
    while (true)
    {
        DataIdx::Entry *ep = dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        cout << "Entry at offset " << ep->offset << endl;

        Psych psych;
        psych.get(ep->key);
        psych.put(newStorage, ep->key);
    }
}
