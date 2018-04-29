//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " ratings\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    "      --help (-h)      - provide this help\n"
    "      --version (-v)   - show version information and terminate\n"
    "   ratings             - csv file produced by `form'.\n"
    "\n";
}
