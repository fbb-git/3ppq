inline Uint32 Tools::size(std::ostream &stream)
{
    return stream.seekp(0, std::ios::end).tellp();
}
