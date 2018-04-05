#include "psychologist.ih"

// static
Psychologist::Record Psychologist::getUnencrypted(string const &data)
{
    size_t skip = 8;

    return
        {
//            *reinterpret_cast<uint16_t const *>(&data.front() + 8),
//            *reinterpret_cast<uint16_t const *>(&data.front() + 8 +
//                                                        sizeof(uint16_t)),
//            data.substr(8 + 2 * sizeof(uint16_t), 16)

            *Tools::as<uint16_t const>(&skip, data),    // ack, beyond IV
            *Tools::as<uint16_t const>(&skip, data),    // nr, beyond ack
            data.substr(skip, 16)                       // pwd hash
        };
}
