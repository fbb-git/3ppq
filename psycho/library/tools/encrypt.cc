#include "tools.ih"

// static
string Tools::encrypt(string const &iv, string const &data)
{
    istringstream in{ data };

    ISymCryptStream<ENCRYPT> encryptor{ in, "bf-cbc", key(), iv };
    
    ostringstream out;

    out << encryptor.rdbuf();   // insert the encrypted contents

    return out.str();           // return the encrypted text
}
