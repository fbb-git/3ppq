template<typename Type>
bool Tools::writeN(std::ostream &out, Uint32 offset, 
                 Type const *src, size_t nToWrite)
{
    out.clear();
    out.seekp(offset);

    return static_cast<bool>
            (out.write(reinterpret_cast<char const *>(src), 
                       nToWrite * sizeof(Type)));
}

