#include "psych.ih"

void Psych::htpasswd(std::string const &pwd) const
{
    string command{
                    g_config.findKeyTail("htpasswd:") + " -b -c " +
                    g_options.htaccessDir() + to_string(d_ID) + ' ' +
                    d_email + ' ' + pwd
                };

    Tools::childProcess(command);                                       
}
