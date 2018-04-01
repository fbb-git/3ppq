#include "tools.ih"

string Tools::md5hash(string const &text)
{
    DigestBuf digestbuf{ "md5" };
    ostream out(&digestbuf);

    out << text;
    digestbuf.close();

    return digestbuf.hash();
}
