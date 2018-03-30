template<typename Type>
bool Tools::write(std::ostream &out, Type const *src, size_t size)
{
    out.clear();
    return static_cast<bool>
            (out.write(reinterpret_cast<char const *>(src), size));
}

