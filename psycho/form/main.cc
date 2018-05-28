#include "main.ih"

namespace {

#include "../basedir.f" // abs. path to the website's base directory

} // anonymous


Options g_options{ g_base };

Log         g_log{ g_options.log() };           // generic log facility
ConfigFile  g_config{ g_options.config(), ConfigFile::RemoveComment };
Mailer      g_mailer;

int main(int argc, char **argv)
try
{
    if (argc > 1 and "--version"s == argv[1])
    {
        cout << "V " << version << '\n';
        return 0;
    }
        
    Tools::setLogLevel();

    Handler handler;                    // Form handling object
    handler.process();                  // process incoming forms
}
catch ([[maybe_unused]] Tools::ForkChild done)
{
    return 0;
}
catch (exception const &exc)
{
    g_log.setLevel(0);
    g_log << "EXCEPTION: " << exc.what() << endl;
}
catch (...)
{
    g_log.setLevel(0);
    g_log << "Unexpected exception" << endl;
}

