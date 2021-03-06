#include <iostream>
#include <string>

#include <bobcat/log>
#include <bobcat/configfile>

using namespace std;
using namespace FBB;

#include "../report.h"
#include "../../../support/options/options.h"
#include "../../../support/wipdata/wipdata.h"

namespace {

#include "../../../basedir.f" // abs. path to the website's base directory

} // anonymous


Options g_options{ g_base };
Log     g_log{ "/tmp/log" };           // generic log facility
ConfigFile  g_config{ g_options.config(), ConfigFile::RemoveComment };

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "1 arg: wipdata file,\n"
                "2 args: 1st is pid.cid, pid.cid.csv must exist\n"
                "       2nd is psych e-mail\n";
        return 0;
    }

    if (argc == 2)
    {
        WIPdata wipData;
        wipData.read(argv[1]);

        Report report{ wipData };
        report.generate();
    }
    else
    {
        Report report{ argv[1], argv[2] };
        report.generate();
    }
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cout << "unexpected exception\n";
    return 1;
}
