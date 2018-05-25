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

    if (argc > 1 and "--version"s == argv[1])
    {
        cout << "V " << version << '\n';
        return 0;
    }
        

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

            Glob glob{ g_options.reportsDir() + ID + ".*" };
            for (auto const *name: glob)
            {
                if (unlink(name) != 0)
                    g_log << "could not remove `" << name << '\'' << endl;
            }
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

