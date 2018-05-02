#include "wipdata.ih"

void WIPdata::read(istream &in)
{
g_log << "WIPdata::read" << endl;
    Tools::readN(in, &d_psychID);

    getline(in, d_clientIdent);

    Tools::readN(in, &d_start);
    Tools::readN(in, &d_clientLogin);

    for (auto &login: d_otherLogin)
        Tools::readN(in, &login);

    Tools::readN(in, d_selfRatings, Tools::N_QUESTIONS);
    Tools::readN(in, d_metaRatings, Tools::N_QUESTIONS);

    for (auto &ratings: d_otherRatings)
        Tools::readN(in, ratings, Tools::N_QUESTIONS);

    string iv;
    Tools::readN(in, iv, Tools::IV_SIZE);

    uint16_t size;
    Tools::readN(in, &size);

    string encrypted;
    Tools::readN(in, encrypted, size);

    string decrypted;
    istringstream addresses{ decrypted = Tools::decrypt(iv, encrypted) };

    Tools::readN(addresses, &d_gender);
    getline(addresses, d_clientName);
    getline(addresses, d_psychEmail);

    for (auto &mail: d_otherEmail)
        getline(addresses, mail);

g_log << "WIPdata::read DONE" << endl;
}




