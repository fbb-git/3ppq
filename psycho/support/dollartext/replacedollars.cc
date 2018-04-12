#include "dollartext.ih"

string const &DollarText::replaceDollars(string &line) const
{
    line += '\n';           // terminate the line, but also make sure that
                            // $ is never the last character

    size_t pos = line.length();

    while (true)
    {
        pos = line.rfind('$', pos);
        if (pos == string::npos)
            return line;

        if (not isdigit(line[pos + 1]))             // no digit
        {
            --pos;                                  // try before pos
            continue;
        }

        size_t idx = stoul(line.substr(pos + 1));   // convert to index

        if (idx < d_dollarText.size())               // valid index
            line.replace(pos, 2, d_dollarText[idx]); // so replace

        --pos;                                  // continue before
    }

    return line;
}

