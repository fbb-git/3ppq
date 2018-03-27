#include "display.ih"

void Display::copy()
{
    while (true)
    {
        if (d_line.empty() && not getline(d_file, d_line))
            return;

        while (true)
        {
            size_t pos = d_line.find("\\$");
            if (pos == string::npos)
            {
                cout << d_line << endl;
                d_line.clear();
                break;
            }
            
            cout << d_line.substr(0, pos);
            d_line.erase(0, pos + 2);
            return;
        }
    }
}
