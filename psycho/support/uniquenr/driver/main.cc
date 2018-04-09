#include <iostream>
#include <string>

#include <bobcat/log>

#include "../uniquenr.h"
#include "../../options/options.h"

Options g_options{ "data/" };

FBB::Log g_log { g_options.log() };

using namespace std;

int main()
try
{
    for (size_t idx = 0; idx != 10; ++idx)
        cout << UniqueNr::get(1, 20) << ' ';

    cout << "\nEnter a number to find or ^D:\n";
    while (true)
    {
        cout << "? ";
        uint16_t nr;
        cin >> nr;
        if (!cin)
            break;

        UniqueNr::rm(nr);
    }

}
catch (...)
{
    return 1;
}
