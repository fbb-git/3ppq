//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << author << "\n" <<
    progname << " V" << version << " " << years << "\n"
    "\n"
    "Usage: " << progname << R"R( option data [newData]
Where:
   option - action to perform (short options between parentheses)
       --expired (-e) nDays: remove psychologist registrations (older
               than `nDays' days) unless acknowledgements were received
       --remove (-r) email|offset: remove a record by email or offset
       --help (-h): show this help information
       --list (-l): list all entries + stored e-mail addresses in 'data'
       --log (-L): name of the log file (by default: 'log')
       --modify (-m): modify all records (in 'data') after modifying Psych's
               toString member, defining a new data organization. 
               Following the modification, update Psych's read function 
               accordingly see also README.modify. The new data are written to 
               'newData'
        --version (-v): show the program's version number

    'data': current psych-data file. The file 'data.idx' must be available. 
    'newData': new data file written by --expired, --remove and --modify.
               also writes 'newData.idx' 
)R";

    throw 0;
}
