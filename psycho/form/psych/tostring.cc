#include "psych.ih"

string Psych::toString() const
{
    ostringstream out;                      // encrypt confidential data

    Tools::writeN(out, &d_nip);
    Tools::writeN(out, &d_field);
    out <<  d_name      << '\n' <<
            d_lastName  << '\n' <<
            d_email     << '\n';

    string iv = Tools::iv();
    string encrypted = Tools::encrypt(iv, out.str());

    out.str("");                            // convert client info to string
    for (auto const &client: d_client)    
    {
        string clientStr = client.toString();
        uint16_t size = clientStr.size();
        Tools::writeN(out, &size);
        Tools::write(out, clientStr);
    }
    string clientData = out.str();

    out.str("");                            // write the Psych's data    

    Tools::write(out, iv);                  // first the encryption IV
    Tools::writeN(out, &d_time);
    Tools::writeN(out, &d_ack);
    Tools::writeN(out, &d_flags);
    Tools::writeN(out, &d_ID);
    Tools::write(out, d_pwdHash);

    uint16_t size = encrypted.size();       // write size of encrypted data
    Tools::writeN(out, &size);
    Tools::write(out, encrypted);           // and the data themselves    


    size = d_client.size();             // # of client data elements
    Tools::writeN(out, &size);
    if (size)
        Tools::write(out, clientData);      // write the client data

    return out.str();                       // return the binary string    
}



