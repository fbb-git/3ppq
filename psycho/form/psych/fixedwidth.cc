#include "psych.ih"

// static
string Psych::fixedWidth(string const &txt, size_t length, Manipulator align)
{
    string blanks;
    for (size_t idx = ret.length(); idx < length; ++idx)
        blanks += "&nbsp;";

    return align == std::left ? txt + blanks : blanks + txt;
}
