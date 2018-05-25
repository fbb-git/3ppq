#include "main.ih"

namespace {

#include "../basedir.f"

}   // anonymous

Options g_options{ g_base };

Log g_log{ g_options.log() };

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
        
    if (argv[1] == "list"s)
        list();
    else if (argv[1] == "expired"s)
        expired();
    else if (argv[1] == "modify"s and argc == 3)
        modify(argv[2]);
    else
        usage(basename(argv[0]));
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
