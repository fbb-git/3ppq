#include "main.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption{"help", 'h'},
        Arg::LongOption{"version", 'v'},
    };
    auto longEnd = longOptions + size(longOptions);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hv", longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, Icmbuild::version, 2);

    Ratings ratings(argv[1]);

    Fscores fscores(ratings.data());

    writeTable(argv[2], fscores.table());

    Gnuplot gnuplot{ ratings, fscores.scores() };
    gnuplot.plot();
}
catch (int x)
{
    return Arg::instance().option("hv") != 0 ? 0 : x;
}
catch (exception const &exc)
{
    cout << exc.what() << endl;
    return 1;
}


