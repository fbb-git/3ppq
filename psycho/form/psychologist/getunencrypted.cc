#include "psychologist.ih"

// static
Psychologist::Record Psychologist::getUnencrypted(string const &data)
{
    size_t skip = 8;
    return 
        {
            *Tools::as<uint16_t const>(&skip, data),  // ack, beyond IV
            *Tools::as<uint16_t const>(&skip, data),  // nr, beyond ack
            data.substr(skip, skip + 16)              // pwd hash
        };
}
