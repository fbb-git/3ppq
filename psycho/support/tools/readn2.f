template<typename Type>
size_t Tools::readN(std::istream &in, Type *dest, size_t nToRead)
{
    in.clear();
    return in.read(
                reinterpret_cast<char *>(dest), nToRead * sizeof(Type)
            ).gcount() / sizeof(Type);
}
