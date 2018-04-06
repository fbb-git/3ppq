#include "psych.ih"

string Psych::getData()
{
    string ret;

    d_psychData.get(&ret, nipKey());

    if (ret.empty())
    {
        g_log << "NIP `" << d_cgi.param1("nip") << "' not registered" << endl;
//        this_thread::sleep_for(chrono::seconds(5));
        Display{ g_options.html() + "unknownpsych" };
        return ret;
    }

    getUnencrypted(ret);

    return ret;
}
