#include "main.ih"

namespace {

#include "basedir.f" // abs. path to the website's base directory

} // anonymous


Options g_options{ g_base };

Log         g_log{ g_options.log() };           // generic log facility
ConfigFile  g_config{ g_options.config(), ConfigFile::RemoveComment };
Mailer      g_mailer;

int main()
try
{
g_log << 1 << endl;

    Handler handler;                    // Form handling object

g_log << 2 << endl;

    handler.process();                  // process incoming forms
}
catch (exception const &exc)
{
    g_log << "EXCEPTION: " << exc.what() << endl;
}

