//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << R"( action
Where:
   action - action to perform
       list:   list all entries + stored e-mail addresses
       modify: modify all records (after modifying the Psych's toString 
               member, defining a new data organization. Following the
               modification, update the Psych's read function accordingly

)";
    throw 0;
}
