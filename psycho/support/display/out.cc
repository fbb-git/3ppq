#include "display.ih"

void Display::out(string const &path)
{
    ifstream in;
    Exception::open(in, path);

    if (d_dollarText.empty())
        cout << in.rdbuf();                 // no variables: file to cout
    else
    {
        string line;
        while (getline(in, line))
            cout << d_dollarText.replaceDollars(line) << '\n';
    }

    cout << "\n"
            "</form>\n"
            "<hr>\n";

    d_dollarText.clear();                    // clear info after calling out
    d_append.clear();
    cout.clear();

}
