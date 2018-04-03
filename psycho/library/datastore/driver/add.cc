#include "main.ih"

void add()
{
    string line;

    while (true)
    {
        cout << "key + text or 'q' or Enter: ";
        if (not getline(cin, line) || line.empty())
            return;

        if (line == "q")
            throw 0;

        string iv = Tools::iv();

        string enc = Tools::encrypt(iv, line);
        string stored = line + '\n' + iv + enc;
                       

        cout << "line length: " << line.length() << '\n';
        cout << "enc length: " << enc.length() << '\n';
        cout << "stored length: " << stored.length() << '\n';
        uint64_t key = stoull(line);

        if (not dataStore.add(key, stored))
            cout << "key " << key << " already stored\n";
    }
}
