#include "main.ih"

namespace {

#include "basedir.f"    // abs. path to the directory containing data files

} // anonymous

Options g_options{ g_base };
Log g_log{ g_options.log() };           // generic log facility

int main()
try
{
    Handler handler;                    // Form handling object

    handler.process();                  // process incoming forms
}
catch (exception const &exc)
{
    g_log << "EXCEPTION: " << exc.what() << endl;
}

