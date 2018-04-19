#include "psych.ih"

bool Psych::get()
{
    string data;

    d_data.get(&data, emailKey());

    if (data.empty())
    {
        notRegistered();
        return false;
    }

    istringstream in(data);                  // read the data

    string iv(Tools::IV_SIZE, 0);
    Tools::read(in, &iv.front(), Tools::IV_SIZE);   // first the IV

    Tools::readN(in, &d_time);              // then the data
    Tools::readN(in, &d_ack);
    Tools::readN(in, &d_flags);
    Tools::readN(in, &d_ID);
    Tools::readN(in, &d_lastClientID);
    d_pwdHash.resize(Tools::HASH_SIZE);
    Tools::read(in, &d_pwdHash.front(), Tools::HASH_SIZE);

    uint16_t size;                          // read size of encrypted data
    Tools::readN(in, &size);

    string decrypted(size, 0);
    in.read(&decrypted.front(), size);      // then the encrypted data
    decrypted = Tools::decrypt(iv, decrypted);  // and decrypt them


//    size = d_client.size();             // # of client data elements
    Tools::readN(in, &size);

g_log << "Reading data of " << size << " clients" << endl;

    if (size)
    {
        d_client.resize(size);          // read # ClientData records

        for (auto &clientData: d_client)
        {
            Tools::readN(in, &size);        // size of the data
            string data(size, 0);
                                            // read the ClientData bytes
            Tools::read(in, &data.front(), size);
            clientData.get(data);
        }
    }

    in.str(decrypted);                      // obtain the confidential data
    Tools::readN(in, &d_nip);
    Tools::readN(in, &d_field);
    getline(in, d_name);
    getline(in, d_lastName);
    getline(in, d_email);

    return true;
}




