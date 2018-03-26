#include "main.ih"

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw Exception{} << 
                    "provide argument e to encrypt, d to decrypt cin";

    string action{ argv[1] == "e"s ? "--encrypt " : "--decrypt " };

    Process process{
        Process::CIN | Process::COUT | Process::IGNORE_CERR, 
        Process::NO_PATH,
        "/usr/bin/gpg "
        "--homedir /home/frank/src/psycho/src/pgphandler/.gnupg "
        "--batch "
        "--pinentry-mode loopback "
        "--passphrase-fd 0 " 
        "--decrypt thefile.gpg"
    };

    string pwd = password();

    process.start();

    process << pwd << eoi;

    cout << "here's the output:\n" << process.childOutStream().rdbuf() << '\n';

//    cout << pwd << '\n';

//    process.start();
//    cout << process.childOutStream().rdbuf();

}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}

