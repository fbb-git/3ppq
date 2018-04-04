template <typename Type>

inline Type *Tools::as(size_t *skip, std::string const &str)
{
    Type *ret = reinterpret_cast<Type *>(&str.front() + *skip);
    *skip += sizeof(Type);

    return ret;
}
