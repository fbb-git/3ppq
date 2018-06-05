#include "main.ih"

int list(string const &data)
{
    DataIdx dataIdx(data + ".idx");

    uint64_t offset = 0;
    while (true)
    {
        DataIdx::Entry *ep = dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        cout << "Entry at offset " << ep->offset << endl;

        Psych psych{ data };
        psych.get(ep->key);

        if (psych.eMail().empty())
            cout << "   (ghost)\n";
        else
            cout << psych << '\n';
    }
    return 0;
}
