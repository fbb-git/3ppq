#include "tools.ih"

// static
string Tools::encrypt(string const &iv, stringstream &&str)
{
    str.seekg(0);

    ISymCryptStream<ENCRYPT> encryptor{ str, "bf-cbc", key(), iv };
    
    str.str("");                // clear the original contents

    str << encryptor.rdbuf();   // insert the encrypted contents

    return str.str();           // return the encrypted text
}
