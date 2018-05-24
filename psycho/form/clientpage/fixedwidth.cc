#include "clientpage.ih"

// static
string ClientPage::fixedWidth(string const &txt, size_t length, 
                              Tools::Align align)
{
    string blanks;

    length -= (align == Tools::RIGHT);

    for (size_t idx = txt.length(); idx < length; ++idx)
        blanks += "&nbsp;";

    return align == Tools::LEFT ? txt + blanks : blanks + txt + "&nbsp;" ;
}
