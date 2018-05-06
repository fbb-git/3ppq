#include "main.ih"

void list()
{
    DataIdx dataIdx(g_options.psych() + ".idx");

    uint64_t offset = 0;
    while (true)
    {
        DataIdx::Entry *ep = dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        cout << "Entry at offset " << ep->offset << endl;

        Psych psych;
        psych.get(ep->key);

        cout << "   e-mail: " << psych.eMail() << endl;
    }
}
