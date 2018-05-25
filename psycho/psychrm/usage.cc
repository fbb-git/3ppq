//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << author << "\n" <<
    progname << " V" << version << " " << years << "\n"
    "\n"
    "Usage: " << progname << " e-mail address\n"
    "Where:\n"
    "   e-mail address   - remove the psychologist from the data store\n"
    "                      whose e-mail is specified.\n"
    "\n";

    throw 0;
}
