#include "psych.ih"

void Psych::tryAdd()
{
    LockGuard lg{ d_lockPath, d_lockFd };

//    g_log << "tryAdd" << endl;

    if (not acceptSignup())
        Display{ g_options.html() + "rejectsignup" };
}

