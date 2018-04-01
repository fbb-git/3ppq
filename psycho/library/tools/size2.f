inline uint64_t Tools::size(std::ostream &stream)
{
    return stream.seekp(0, std::ios::end).tellp();
}
