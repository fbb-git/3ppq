#include "psych.ih"

string Psych::toString() const
{
    ostringstream out;                      // encrypt confidential data

    Tools::writeN(out, &d_gender, 1);
    out <<  d_name      << '\n' <<
            d_lastName  << '\n' <<
            d_email     << '\n';

g_log << "Psych::toString encrypt conf.data" << endl;

    string iv = Tools::iv();
    string encrypted = Tools::encrypt(iv, out.str());

g_log << "encrypted " << encrypted.size() << " bytes" << endl;

    out.str("");                            // convert client info to string
    for (auto const &client: d_client)    
    {
        string clientStr = client.toString();
        uint16_t size = clientStr.size();
        Tools::writeN(out, &size);
        Tools::write(out, clientStr);
    }
    string clientData = out.str();

g_log << "clientData" << endl;

    out.str("");                            // write the Psych's data    

    Tools::write(out, iv);                  // first the encryption IV
    Tools::writeN(out, &d_time);
    Tools::writeN(out, &d_ack);
    Tools::writeN(out, &d_flags);
    Tools::writeN(out, &d_ID);
    Tools::writeN(out, &d_nip);
    Tools::write(out, d_pwdHash);

    uint16_t size = encrypted.size();       // write size of encrypted data
    Tools::writeN(out, &size);
    Tools::write(out, encrypted);           // and the data themselves    


    size = d_client.size();             // # of client data elements
    Tools::writeN(out, &size);
    if (size)
        Tools::write(out, clientData);      // write the client data

g_log << "total length: " << out.str().size() << endl;
    
    return out.str();                       // return the binary string    
}



