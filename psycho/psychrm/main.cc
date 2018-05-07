#include "main.ih"

namespace {

#include "../basedir.f"

}   // anonymous

Options g_options{ g_base };
ConfigFile  g_config{ g_options.config(), ConfigFile::RemoveComment };

Log g_log { "/tmp/log" };

int main(int argc, char **argv)
try
{
    if (argc == 1)
        usage(basename(argv[0]));

    string hash = Tools::md5hash(argv[1]);      // hash the psych's e-mail

    Psych psych;

    if (not psych.get(hash))                    // get the psych's record
        cout << argv[1] << " not found\n";
    else
    {
        string ID { to_string(psych.ID()) };

        cout << "E-mail: " << psych.eMail() << ", ID: " << ID << '\n';

        DataStore dataStore{ g_options.psych() };
        LockGuard lg{ dataStore.lg() };

        if (dataStore.erase(hash))              // erase it
        {
            cout << argv[1] << "(ID = " << ID << ") was removed\n";

                                                // remove the htaccess/ID file
            Tools::childProcess(g_config.findKeyTail("rm:") + " -f " +
                                g_options.htaccessDir() + ID);
            cout << g_options.htaccessDir() + ID << " was removed\n";

                                                // remove the results/ID dir
            Tools::childProcess(g_config.findKeyTail("rm:") + " -rf " +
                                g_options.resultsDir() + ID);
            cout << "directory " << g_options.resultsDir() + ID << 
                    " was removed\n";
        }
    }
}
catch (int)
{
    return 0;
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
}
catch (...)
{
    cout << "unexpected exception\n";
    return 1;
}

