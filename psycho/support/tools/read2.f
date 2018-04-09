template<typename Type>
size_t Tools::read(std::istream &in, Type *dest, size_t size)
{
    in.clear();
    return in.read(
                reinterpret_cast<char *>(dest), size
            ).gcount() / sizeof(Type);
}
