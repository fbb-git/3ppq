#include "tools.ih"

// static
string Tools::decrypt(string const &iv, stringstream &&str)
{
    ISymCryptStream<DECRYPT> decryptor{ str, "bf-cbc", key(), iv };
    
    str.str("");                // clear the original contents

    str << decryptor.rdbuf();   // insert the decrypted contents

    return str.str();           // return the decrypted text
}
