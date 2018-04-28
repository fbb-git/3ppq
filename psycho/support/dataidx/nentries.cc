#include "dataidx.ih"

// static
uint16_t DataIdx::nEntries(istream &dataIdx)
{
    uint16_t header[sizeHeader];

    Tools::readB(dataIdx, header, sizeof(header));
    return header[N_KEYS]; 
}
