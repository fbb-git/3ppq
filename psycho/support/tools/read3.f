inline size_t Tools::read(istream &in, string &dest)
{
    in.clear();
    return in.read(&dest.front(), dest.size()).gcount();
}
