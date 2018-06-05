#include "main.ih"

namespace {

Arg::LongOption longOptions[] =
{
    Arg::LongOption{"expired", 'e'},
    Arg::LongOption{"list", 'l'},
    Arg::LongOption{"log", 'L'},
    Arg::LongOption{"modify", 'm'},

    Arg::LongOption{"help", 'h'},
    Arg::LongOption{"version", 'v'},
};
auto longEnd = longOptions + size(longOptions);

}   // anonymous

//Options g_options{ g_base };

Log g_log;

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("elL:m:hv", longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, version, 1);

    string logName;
    g_log.open(
            arg.option(&logName, 'L') ?
                logName
            :
                "log"s
    );

    if (arg.option('l'))
        return list(arg[0]);

    if (arg.option('e'))
        return expired(arg[0]);

    string newData;
    if (arg.option(&newData, 'm'))
        return modify(arg[0], newData);

    arg.help();
}
catch (int)
{
    return 0;
}
catch (exception const &exc)
{
    if (Arg::instance().option("hv"))
        return 0;

    cout << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cout << "unexpected exception\n";
    return 1;
}
