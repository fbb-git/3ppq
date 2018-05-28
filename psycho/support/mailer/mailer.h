#ifndef INCLUDED_MAILER_
#define INCLUDED_MAILER_

#include <iosfwd>
#include <string>

#include <bobcat/fork>

class Mailer: private FBB::Fork
{
    std::string d_txt;
    std::string d_to;
    std::string d_subject;

    public:
        void sendmail(std::string const &psychEmail, std::string to, 
                      std::string const &subject, std::string const &txt);

    private:
        void childProcess() override;
        void parentProcess() override;
};

extern Mailer g_mailer;

#endif
