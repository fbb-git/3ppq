#include "psych.ih"

void Psych::client()
{
    LockGuard lg{ d_lockPath, d_lockFd };

    if (not get())
        return;

   
    // show client data, modify / delete 

    // add client:
}
