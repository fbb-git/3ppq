inline uint64_t Tools::size(std::istream &stream)
{
    return stream.seekg(0, std::ios::end).tellg();
}
