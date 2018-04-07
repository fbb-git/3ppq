#ifndef INCLUDED_CLIENT_
#define INCLUDED_CLIENT_

#include <unordered_map>

#include "../../support/datastore/datastore.h"
#include "../../support/types/types.h"

namespace FBB
{
    class CGI;
};

class Client
{
    typedef std::unordered_map<std::string, void (Client::*)()> Map;

    FBB::CGI &d_cgi;

    int d_nQuestions;               // compared against negative values
                                    // in quest.cc, hence 'int'
    StrVector d_lines;

    static Map s_state;             // maps state names to handling functions

    public:
        Client(FBB::CGI &cgi);
        void process();

    private:
        void verify();
        void quest();           // question 0: 1st question, no back
                                // last q.: no next, but finish
};
        
#endif
