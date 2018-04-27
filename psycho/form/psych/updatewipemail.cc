#include "psych.ih"

vector<LockGuard> Psych::updateWIPemail() const
{
    Glob glob{ 
            g_options.dataDir() + to_string(d_ID) + '.', 
            Glob::NOMATCH, Glob::DEFAULT 
        };

    vector<LockGuard> lg;

    for (string name: glob)
    {
        if (name.find(".lck") != string::npos)  // ignore lck files
            continue;
        
        name += '=';
        WIPdata wipData{ name.substr(name.rfind('/') + 1) };

        lg.push_back(wipData.read());
        wipData.setPsychEmail(d_email);
        wipData.write();
    }

    return lg;
}
