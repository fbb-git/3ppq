#include "psychencrypted.ih"

void PsychEncrypted::get(string const &iv, string const &data)
{
    istringstream in{ Tools::decrypt(iv, data) };

    Tools::read(in, &d_nip);
    Tools::read(in, &d_gender, 1);

    getline(in, d_name);
    getline(in, d_lastName);
    getline(in, d_email);

//    g_log << "private data: " << 
//                d_nip << ", " <<
//                d_gender << ", " <<
//                d_name << ", " <<
//                d_lastName << ", " <<
//                d_email << endl;
}
