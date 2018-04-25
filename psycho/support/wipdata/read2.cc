#include "wipdata.ih"

LockGuard WIPdata::read()
{
    string name = path();

    d_io = LockStream{ name };

    LockGuard lg{ d_io.lg() };

    if (not Tools::exists(name))
        throw false;

    d_io.open();
    read(d_io);

    return lg;
}
