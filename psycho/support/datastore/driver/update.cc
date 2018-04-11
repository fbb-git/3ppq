#include "main.ih"

void update()
{
    while (true)
    {
        cout << "key + text to update or 'q' or Enter: ";

        string line;
        if (not getline(cin, line) || line.empty())
            return;

        if (line == "q")
            throw 0;

        string key = line.substr(0, line.find_first_of(' '));
        key.resize(Tools::KEY_SIZE);

        string store = prepare(line);

        if (not dataStore.update(key, store))
            cout << "key " << key << " not available\n";
    }

}
