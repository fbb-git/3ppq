#include "tools.ih"

Uint16 Tools::htmlTextSize(StrVector const &htmlTexts)
{
    return htmlTexts.size() + 
            accumulate(htmlTexts.begin(), htmlTexts.end(), 0, 
                [&](Uint16 value, string const &str)
                {
                    return value + str.length();
                }
            );
}
