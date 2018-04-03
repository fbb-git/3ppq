#include "main.ih"

void update()
{
    string line;

    while (true)
    {
        cout << "key + text to update or 'q' or Enter: ";
        if (not getline(cin, line) || line.empty())
            return;

        if (line == "q")
            throw 0;

        uint64_t key = stoull(line);

        if (not dataStore.update(key, line))
            cout << "key " << key << " not available\n";
    }

}
