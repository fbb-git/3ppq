#include "psych.ih"

bool Psych::get()
{
    string data;

    d_data.get(&data, emailKey());

    if (data.empty())
    {
        notRegistered();
        return false;
    }

    read(data);

    return true;
}




