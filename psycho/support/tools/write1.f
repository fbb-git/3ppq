template<typename Type>
bool Tools::write(std::ostream &out, Uint32 offset, 
                 Type const *src, size_t size)
{
    out.clear();
    out.seekp(offset);

    return static_cast<bool>
            (out.write(reinterpret_cast<char const *>(src), size));
}

