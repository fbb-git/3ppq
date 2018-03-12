#ifndef INCLUDED_MAIL_
#define INCLUDED_MAIL_

#include <vector>

#include <bobcat/mailheaders>
#include <bobcat/user>

class Mail
{

    struct Psych
    {
        enum 
        {
            NAME,
            EMAIL,
            ID
        };
    };

    template <size_t shift = 0>
    struct Shift
    {
        enum
        {
            CLIENT = shift,
            GENDER,
            E_MAIL,
            PRE_ID,
            ASS1,
            ASS1_MAIL,
            ASS2,
            ASS2_MAIL,
            ASS3,
            ASS3_MAIL,
            size
        };
    };
        
    struct Fields: public Shift<0>
    {};

    struct Clients: public Shift<4>
    {
        enum
        {
            ID,
            PSYCH_ID,
            LOGIN,
            POST_ID,
        };
    };        


    FBB::User                   d_user;
    FBB::MailHeaders            d_mh;
    std::vector<std::string>    d_psych;    // details of the psych. sending 
                                            // this e-mail

    static char const s_begin[];
    static char const s_end[];
    static char const s_psychologists[];
    static char const s_clients[];

    public:
        Mail();
        void process();
    private:
        void checkEnvelope();
        void checkID();
        void clientInfo();          // retrieve the ---BEGIN ... info
        std::string beginSection();
        void clientFields(std::string const &line);
        void uniquePreID(std::string const &preID);
        [[noreturn]] void mail(std::string const &msg);
};

#endif
