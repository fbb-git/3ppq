inline Uint32 Tools::size(std::fstream &stream)
{
    return stream.seekg(0, std::ios::end).tellg();
}
