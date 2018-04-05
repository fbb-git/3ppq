#include "psych.ih"

// static
bool Psych::acceptNr(istream &nrs, uint16_t idNr)
{
    uint16_t *buffer = new uint16_t[100];

    while (true)
    {
                                                // read 'nRead' numbers
        uint64_t nRead = nrs.read(reinterpret_cast<char *>(buffer),
                                  100 * sizeof(uint16_t)).gcount()
                         / sizeof(uint16_t);

        if (nRead == 0)                         // all numbers inspected
        {
            delete[] buffer;
            return true;                        // accept idNr
        }

                                                // number already used
        if (find(buffer, buffer + nRead, idNr) != buffer + nRead)
        {
            delete[] buffer;
            return false;                       // try another idNr
        }
    }
}
