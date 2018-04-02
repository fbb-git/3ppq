#include "main.ih"

int main(int argc, char **argv)
try
{
    DataStore data{ "data/data" };

    string line;
    while (true)
    {
        while (true)
        {
            cout << "key + text or 'q' or Enter: ";
            if (not getline(cin, line) || line.empty())
                break;

            if (line == "q")
                return 0;

            if (not data.add(stoull(line), line))
                cout << "key " << stoull(line) << " already stored\n";
        }
    
        while (true)
        {
            cout << "key to retrieve or 'q' or Enter: ";
            if (not getline(cin, line) || line.empty())
                break;

            if (line == "q")
                return 0;
    
            if (not data.get(&line, stoull(line)))      // just provide the key
                cout << "key " << stoull(line) << " not available\n";
            else
                cout << line << '\n';
        }

        while (true)
        {
            cout << "key + text to update or 'q' or Enter: ";
            if (not getline(cin, line) || line.empty())
                break;

            if (line == "q")
                return 0;
    
            if (not data.update(stoull(line), line)) 
                cout << "key " << stoull(line) << " not available\n";
        }

        while (true)
        {
            cout << "key to remove or 'q' or Enter: ";
            if (not getline(cin, line) || line.empty())
                break;

            if (line == "q")
                return 0;
    
            if (not data.erase(stoull(line)))      // just provide the key
                cout << "key " << line << " not available\n";
            else
                cout << "key " << line << " removed\n";
        }
    }
}
catch (exception const &exc)
{
    cout << "Exception: " << exc.what() << '\n';
}
