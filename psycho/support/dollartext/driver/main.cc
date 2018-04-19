#include <iostream>
#include <string>

#include "../dollartext.h"
#include "../../options/options.h"

#include "../../../form/basedir.f"

using namespace std;

Options g_options{ g_base };

int main(int argc, char **argv)
try
{
    if (argc == 1)
        cout << "provide file argument\n";
    else
        cout << DollarText::replaceStream(argv[1],  
                    {
                        "heer",     // $0
                        "Hofstee",  // $1
                        "123"       // $2
                    }
                ) << '\n';
}
catch (...)
{
    return 1;
}
