#ifndef INCLUDED_PSYCHOLOGIST_
#define INCLUDED_PSYCHOLOGIST_

#include <unordered_map>

namespace FBB
{
    class CGI;
};

class Psychologist
{
    typedef std::unordered_map<std::string, void (Psychologist::*)()> Map;

    static Map s_state;

    FBB::CGI &d_cgi;

    public:
        Psychologist(FBB::CGI &cgi);
        void process();

    private:
        void newPsych();
};
        
#endif
