#include "tools.ih"

    // 16 bytes
string Tools::md5hashText(string const &text)
{
    DigestBuf digestbuf{ "md5" };
    ostream out(&digestbuf);

    out << text;
    digestbuf.close();

    ostringstream hashText;
    hashText << digestbuf;

    return hashText.str();
}
