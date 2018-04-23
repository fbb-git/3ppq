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

    string iv;
    Tools::readN(in, iv, Tools::IV_SIZE);   // first the IV
    Tools::readN(in, &d_time);              // then the data
    Tools::readN(in, &d_ack);
    Tools::readN(in, &d_flags);
    Tools::readN(in, &d_ID);
    Tools::readN(in, d_pwdHash, Tools::HASH_SIZE);

    uint16_t size;                          // read size of encrypted data
    Tools::readN(in, &size);

    string decrypted;
    Tools::readN(in, decrypted, size);      // then the encrypted data
    decrypted = Tools::decrypt(iv, decrypted);  // and decrypt them


    Tools::readN(in, &size);

g_log << "Reading data of " << size << " clients" << endl;

    if (size)
    {
        d_client.resize(size);          // read # ClientData records

        for (auto &clientData: d_client)
        {
            Tools::readN(in, &size);        // size of the data

            string data;                    // read the ClientData bytes
            Tools::readN(in, data, size);
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




