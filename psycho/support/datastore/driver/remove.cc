#include "main.ih"

void remove()
{
    while (true)
    {
        cout << "key to remove or 'q' or Enter: ";

        string line;
        if (not getline(cin, line) || line.empty())
            return;

        if (line == "q")
            throw 0;

        string key = line;
        key.resize(Tools::KEY_SIZE);

        if (not dataStore.erase(key))            // just provide the key
            cout << "key " << line << " not available\n";
        else
            cout << "key " << line << " removed\n";
    }
}
