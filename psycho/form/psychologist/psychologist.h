#ifndef INCLUDED_PSYCHOLOGIST_
#define INCLUDED_PSYCHOLOGIST_

#include <iosfwd>
#include <unordered_map>

namespace FBB
{
    class CGI;
};

class Psychologist
{
    typedef std::unordered_map<std::string, void (Psychologist::*)()> Map;

    struct Record
    {
        std::string name;
        std::string email;
        std::string nip;
        std::string passwd;
        bool        gender;
    };

    static Map s_state;

    FBB::CGI &d_cgi;
    Record d_record;

    public:
        Psychologist(FBB::CGI &cgi);
        void process();

    private:
        bool readRecord(std::istream &in);

        void add();
        void alreadyRegistered();
        void newRegistration();

        void newPsych();
};
        

#endif
