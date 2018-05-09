#include "psych.ih"

bool Psych::get(std::string const &key)
{
    string data;

    {
        LockGuard lg { d_data.lg() };
        d_data.get(&data, key);
    }

    if (data.empty())
        return false;

    read(data);

    return true;
}




