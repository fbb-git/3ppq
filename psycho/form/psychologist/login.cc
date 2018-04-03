#include "psychologist.ih"

    // page opened when the psychologist 
void Psychologist::login()
{
    string data;
    {
        LockGuard lg{ d_lockPath, d_lockFd };
        d_psychData.get(&data, nipKey());
    }

    if (data.empty())
    {
        this_thread::sleep_for(chrono::seconds(5));
        Display{ "unknownpsych" };
        return;
    }

    getUnencrypted(data);

    if (not pwMatch())
    {
        this_thread::sleep_for(chrono::seconds(5));
        Display{ "pwdfailure" };
        return;
    }

    Display{ "actions" };
}
