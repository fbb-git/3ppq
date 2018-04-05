#include "main.ih"

void retrieve()
{
    while (true)
    {
        cout << "key to retrieve or 'q' or Enter: ";

        string line;
        if (not getline(cin, line) || line.empty())
            return;

        if (line == "q")
            throw 0;

        string key = line.substr(0, line.find_first_of(' '));
        key.resize(DataIdx::KEY_SIZE);

        if (not dataStore.get(&line, key))           // just provide the key
            cout << "key " << key << " not available\n";
        else
        {
            cout << "retrieved length: " << line.length() << '\n';

            size_t pos = line.find('\n');
            string first = line.substr(0, pos);
            cout << "first length: " << first.length() << '\n';

            string iv = line.substr(pos + 1, 8);

            string enc = line.substr(pos + 1 + 8, string::npos);
            cout << "encrypted length: " << enc.length() << '\n';

            string decr = Tools::decrypt(iv, enc);

            cout << "first: " << first << '\n' << 
                    "decr: " << decr << '\n';
        }
    }

}

