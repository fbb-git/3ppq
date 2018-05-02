#include <iostream>
#include <string>
#include <exception>

#include "../wipdata.h"

using namespace std;

// arg1: csv-file, arg2: wipfile

int main(int argc, char **argv)
try
{
    if (argc != 3)
    {
        cout << "first arg: data file, 2nd arg: binary wip file to write\n";
        return 0;
    }

    WIPdata wipData{ argv[1], "frank@localhost", true, "Client Name" };

    {
        ofstream out{ argv[2] };
        wipData.write(out);                 // write binary WIP data
    }

//    ifstream in{ argv[2] };               // testing purposes only
//    wipData.read(in);
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
    return 1;
}



