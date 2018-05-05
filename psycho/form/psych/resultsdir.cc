#include "psych.ih"

void Psych::resultsDir(string const &pwd) const
{
    string ID{ to_string(d_ID) };

    string userDir{ g_options.htaccessDir() + ID + '/'};

    Tools::mkdir(userDir);                          // make www/results/ID

    DollarText::replace(                            // write .htaccess
                    userDir + ".htaccess",
                    g_options.moldsDir() + "htaccess",
                    {
                        g_options.baseDir(),
                        ID
                    }
                );

    htpasswd(pwd);
}
