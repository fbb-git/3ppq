template<typename Type>
size_t Tools::read(std::istream &in, Uint32 offset, 
                  Type *dest, size_t size)
{
    in.clear();
    in.seekg(offset);

    return in.read(
                reinterpret_cast<char *>(dest), size
            ).gcount() / sizeof(Type);
}
