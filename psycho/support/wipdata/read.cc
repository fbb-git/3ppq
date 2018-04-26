#include "wipdata.ih"

void WIPdata::read(istream &in)
{
    Tools::readN(in, &d_psychID);
    Tools::readN(in, &d_clientID);
    Tools::readN(in, &d_start);
    Tools::readN(in, &d_clientLogin);


    for (auto login: d_otherLogin)
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
    getline(addresses, d_psychMail);
    getline(addresses, d_clientName);

    for (auto &mail: d_otherMail)
        getline(addresses, mail);
}

