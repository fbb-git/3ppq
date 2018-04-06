#include <iostream>
#include <string>

#include "../dollartext.h"
#include "../../options/options.h"

#include "../../../form/basedir.f"

using namespace std;

Options g_options{ g_base };

int main()
try
{
    cout << DollarText{ 
                "verify",           
                {
                    "heer",     // $0
                    "Hofstee",  // $1
                    "123"       // $2
                }
            }.text();
}
catch (...)
{
    return 1;
}
