#include "wipdata.ih"

LockGuard WIPdata::read()
{
    string name = path();

    d_io = LockStream{ name };

    LockGuard lg{ d_io.lg() };

    if (not Tools::rwExists(name))
    {
        g_log << '`' << name << "' not available" << endl;
        throw Tools::NO_DATA;
    }

    d_io.open();
    read(d_io);

    return lg;
}





