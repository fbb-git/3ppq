inline uint64_t Tools::md5hash8(std::string const &text)
{
    return *reinterpret_cast<uint64_t *>(&md5hash(text).front());
}
