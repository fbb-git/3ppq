#include "psych.ih"

void Psych::tryAdd()
{
    LockGuard lg{ d_data.lg() };

//    g_log << "tryAdd" << endl;

    if (not acceptSignup())
        Display{ g_options.html() + "rejectsignup" };
}

