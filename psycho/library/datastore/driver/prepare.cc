#include "main.ih"

string prepare(string const &line)
{
    cout << "line length: " << line.length() << '\n';

    string iv = Tools::iv();
    string enc = Tools::encrypt(iv, line);

    cout << "enc length: " << enc.length() << '\n';

    string store = line + '\n' + iv + enc;

    cout << "stored length: " << store.length() << '\n';

    return store;
}
