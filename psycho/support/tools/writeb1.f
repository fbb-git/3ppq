template<typename Type>
bool Tools::writeB(std::ostream &out, Type const *src, size_t size)
{
    out.clear();
    return static_cast<bool>
            (out.write(reinterpret_cast<char const *>(src), size));
}

