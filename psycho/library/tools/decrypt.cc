#include "tools.ih"

// static
string Tools::decrypt(string const &iv, string const &data)
{
    istringstream in{ data };
    ISymCryptStream<DECRYPT> decryptor{ in, "bf-cbc", key(), iv };
    
    ostringstream out;
    out << decryptor.rdbuf();   // insert the decrypted contents

    return out.str();           // return the decrypted text
}
