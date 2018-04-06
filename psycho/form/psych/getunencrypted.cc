#include "psych.ih"

void Psych::getUnencrypted(string const &data)
{
    size_t skip = 8;

    d_record = 
        Record
        {
            *Tools::as<uint32_t const>(&skip, data),    // time, beyond IV
            *Tools::as<uint16_t const>(&skip, data),    // ack, beyond time
            *Tools::as<uint16_t const>(&skip, data),    // flags, beyond ack
            *Tools::as<uint16_t const>(&skip, data),    // nr, beyond flags
            data.substr(skip, 16),                       // pwd hash

            sizeof(uint32_t) + 3 * sizeof(uint16_t) + 16
        };
}
