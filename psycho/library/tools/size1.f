inline Uint32 Tools::size(std::istream &stream)
{
    return stream.seekg(0, std::ios::end).tellg();
}
