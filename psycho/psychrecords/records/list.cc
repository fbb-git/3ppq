#include "records.ih"

void Records::list() const
{
    cout << "Defined entries: " << d_dataIdx.size() << '\n';

    uint64_t offset = 0;

    while (true)
    {
        DataIdx::Entry *ep = d_dataIdx.nextEntry(&offset); 
        
        if (ep == 0)
            break;

        cout << "Entry at idx offset " << 
            offset - SHIFT << " (0x" << hex << offset - SHIFT << dec << "),\n"
            "file offset " << ep->offset << 
            " (0x" << hex << ep->offset << dec << ')' << endl;

        Psych psych{ d_data };
        if (psych.get(ep->key))
            cout << psych << '\n';
    }
}
