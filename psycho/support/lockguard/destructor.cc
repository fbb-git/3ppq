#include "lockguard.ih"

LockGuard::~LockGuard()
{
    if (d_fd == -1)
        return;

    if (s_locked[d_path] != 0)
        --s_locked[d_path];

    if (s_locked[d_path] == 0)
    {
        if (not Tools::rwExists(d_path))        // actual file doesn't exits
            unlink( (d_path + ".lck").c_str() );    // then rm the .lck file
        else
        {
            flock(d_fd, LOCK_UN);               // else unlock
            s_locked.erase(d_path);             // and rm from the list of
        }                                       // locked file names
    }
}
