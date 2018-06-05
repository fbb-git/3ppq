//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << author << "\n" <<
    progname << " V" << version << " " << years << "\n"
    "\n"
    "Usage: " << progname << R"R( option data
Where:
   option - action to perform (short options between parentheses)
       --expired (-e): remove expired psychologist registrations (older than
               two days, without received acknowledgements)
       --help (-h): show this help information
       --list (-l): list all entries + stored e-mail addresses in 'data'
       --log (-L): name of the log file (by default: 'log')
       --modify (-m) newData: modify all records (in 'data') after modifying
               Psych's toString member, defining a new data organization. 
               Following the modification, update Psych's read function 
               accordingly see also README.modify. The new data are written to 
               'newData'
        --version (-v): show the program's version number

    The file 'data.idx' must be available. The file 'newData.idx' is also
    written (when using `--modify')
)R";

    throw 0;
}
