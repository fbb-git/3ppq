#include "uniquenr.ih"

// static
bool UniqueNr::acceptNr(istream &nrs, uint16_t idNr)
{
    uint16_t *buffer = new uint16_t[100];

    nrs.clear();
    nrs.seekg(0);

    while (true)
    {
                                                // read 'nRead' numbers
        size_t nRead = Tools::readN(nrs, buffer, 100);

        if (nRead == 0)                         // all numbers inspected
        {
            delete[] buffer;
            return true;                        // accept idNr
        }

        uint16_t *ptr;

                                                // number already used ?
        if ((ptr = find(buffer, buffer + nRead, idNr)) != buffer + nRead)
        {
            delete[] buffer;
            return false;                       // try another idNr
        }
    }
}
