#include "psych.ih"

void Psych::getUnencrypted(string const &data)
{
    size_t skip = 8;

    d_record = 
        Record
        {
            *Tools::as<uint16_t const>(&skip, data),    // ack, beyond IV
            *Tools::as<uint16_t const>(&skip, data),    // nr, beyond ack
            data.substr(skip, 16),                       // pwd hash

            16 + 2 * sizeof(uint16_t)
        };
}
