template<typename Type>
bool Tools::read(std::istream &in, Uint32 offset, 
                 Type *dest, size_t size)
{
    in.clear();
    in.seekg(offset);

    return static_cast<bool>
            (in.read(reinterpret_cast<char *>(dest), size));
}
