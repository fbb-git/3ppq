#include "psych.ih"

void Psych::getPrivate(string const &data, size_t offset)
{
    istringstream in{ 
            Tools::decrypt(
                data.substr(0, 8),          // IV
                string{ data.begin() + offset, data.end() }
            )
        };

    Tools::read(in, &d_private.nip);
    Tools::read(in, &d_private.gender, 1);

    getline(in, d_private.name);
    getline(in, d_private.lastName);
    getline(in, d_private.email);

//    g_log << "private data: " << 
//                d_private.nip << ", " <<
//                d_private.gender << ", " <<
//                d_private.name << ", " <<
//                d_private.lastName << ", " <<
//                d_private.email << endl;

}

