#include "main.ih"

void remove()
{
    string line;

    while (true)
    {
        cout << "key to remove or 'q' or Enter: ";
        if (not getline(cin, line) || line.empty())
            return;

        if (line == "q")
            throw 0;

        uint64_t key = stoull(line);

        if (not dataStore.erase(key))            // just provide the key
            cout << "key " << key << " not available\n";
        else
            cout << "key " << key << " removed\n";
    }
}
