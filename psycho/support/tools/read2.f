template<typename Type>
bool Tools::read(std::istream &in, Type *dest, size_t size)
{
    in.clear();
    return static_cast<bool>
            (in.read(reinterpret_cast<char *>(dest), size));
}
