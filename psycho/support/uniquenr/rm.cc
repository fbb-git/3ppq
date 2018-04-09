#include "uniquenr.ih"

// static
void UniqueNr::rm(uint16_t nr)
{
    string path = g_options.nrs();

    fstream nrs{ Tools::fstream(path) };

    LockGuard lg{ path, s_lockFd };

    string newPath = path + ".tmp";
    fstream newNrs{ Tools::fstream(newPath) };

    uint16_t *buffer = new uint16_t[100];

    while (true)
    {
                                                // read 'nRead' numbers
        size_t nRead = Tools::readN(nrs, buffer, 100);

        if (nRead == 0)                         // all numbers read
            break;
                                                // find the nr. to remove
        uint16_t *ptr = find(buffer, buffer + nRead, nr);
        size_t nrIndex = ptr - buffer;          // and its index

        Tools::writeN(newNrs, buffer, nrIndex); // write nrs up to ptr

                                                // and beyond nr
        Tools::writeN(newNrs, ptr + 1, (nRead - (nrIndex + 1))); 

        if (nrIndex != nRead)                   // nr was found
        {
            newNrs << nrs.rdbuf();
            break;
        }
    }

    delete[] buffer;

    nrs.close();
    newNrs.close();

    Tools::rename(newPath, path);
}


