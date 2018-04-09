template<typename Type>
bool Tools::writeN(std::ostream &out, Type const *src, size_t nToWrite)
{
    out.clear();
    return static_cast<bool>
            (out.write(reinterpret_cast<char const *>(src), 
                       nToWrite * sizeof(Type)));
}

