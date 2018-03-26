#include "main.ih"

// DO NOT RECOMPILE THIS FILE. INSTEAD USE THE PRECOMPILED FILE password.o
// The encoded passphrase is in the file 3ppq-passphrase.gpg, encrypted with
// Frank's PGP key.

unsigned char pwdTxt[] = {
    // to change the password define it here, + some blurr, then 
    // undo the blurr in the password() function.
};

string password()
{
    string ret{pwdTxt, pwdTxt + size(pwdTxt) };
    for (size_t idx = 0; idx != size(pwdTxt); ++idx)
        ;   // undo the blurr.
        

    return ret;
}


