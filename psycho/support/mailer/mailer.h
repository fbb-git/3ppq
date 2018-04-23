#ifndef INCLUDED_MAILER_
#define INCLUDED_MAILER_

#include <iosfwd>
#include <string>

class Mailer
{
    public:
        void sendmail(std::string const &psychEmail, std::string to, 
                      std::string const &subject, std::string const &txt);
};

extern Mailer g_mailer;

#endif
