#include "psych.ih"

    // page opened when the psychologist 
void Psych::login()
{
    string data;
    {
        LockGuard lg{ d_lockPath, d_lockFd };
        d_psychData.get(&data, nipKey());
    }

    if (data.empty())
    {
//        this_thread::sleep_for(chrono::seconds(5));
        Display{ "unknownpsych" };
        return;
    }

    if (not pwdMatch(getUnencrypted(data)))
    {
//        this_thread::sleep_for(chrono::seconds(5));
        Display{ "pwdfailure" };
        return;
    }

    g_log << "actions" << endl;

    Display{ "actions" };
}
