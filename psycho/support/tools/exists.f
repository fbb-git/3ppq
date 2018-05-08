inline bool Tools::rwExists(std::string const &fname)
{
    return access(fname.c_str(), R_OK | W_OK) == 0;
}
