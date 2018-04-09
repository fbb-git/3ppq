template<typename Type>
size_t Tools::readN(std::istream &in, Uint32 offset, 
                  Type *dest, size_t nToRead)
{
    in.clear();
    in.seekg(offset);

    return in.read(
                reinterpret_cast<char *>(dest), nToRead * sizeof(Type)
            ).gcount() / sizeof(Type);
}
