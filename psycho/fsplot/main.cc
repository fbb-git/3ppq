#include "main.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption{"help", 'h'},
        Arg::LongOption{"version", 'v'},
    };
    auto longEnd = longOptions + size(longOptions);

#include "../basedir.f" // abs. path to the website's base directory

} // anonymous

Options g_options{ g_base };
ConfigFile  g_config{ g_options.config(), ConfigFile::RemoveComment };
Log g_log{ g_options.log() };

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hv", longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, Icmbuild::version, 4);

    Ratings ratings{ argv[1] };             // extract the data from the csvs

    Fscores fscores(ratings.data());        // compute the factor scores

    DataFiles dataFiles{ fscores.table() };
    dataFiles.gnuplot(argv[3]);

    dataFiles.scoresTable(argv[4]);

    Gnuplot gnuplot{ ratings, fscores.scores() };

    return gnuplot.plot(argv[2]);
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


