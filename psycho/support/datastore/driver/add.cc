#include "main.ih"

void add()
{
    while (true)
    {
        cout << "key + text or 'q' or Enter: ";
        
        string line;
        if (not getline(cin, line) || line.empty())
            return;

        if (line == "q")
            throw 0;

        string key = line.substr(0, line.find_first_of(' '));
        key.resize(Tools::KEY_SIZE);

        string store = prepare(line);

        if (not dataStore.add(key, store))
            cout << "key " << key << " already stored\n";
        else
            cout << "next nr = " << dataStore.nextNr() << '\n';
    }
}


