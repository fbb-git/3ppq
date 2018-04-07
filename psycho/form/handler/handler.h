#ifndef INCLUDED_HANDLER_
#define INCLUDED_HANDLER_

#include <string>
#include <unordered_map>

#include <bobcat/cgi>

#include "../../support/options/options.h"

#include "../client/client.h"
#include "../psych/psych.h"

class Handler
{
    FBB::CGI            d_cgi;

    Client d_client;
    Psych d_psych;

    public:
        Handler();
        ~Handler();
        void process();

    private:
        void empty();
        void psychoStart();
        void psychoRequest();

        void logParams();
};


//    std::ifstream       d_in;
//    int                 d_toMonitorFd;
//    std::string const  &d_lockPath;
//    std::ofstream       d_out;


//
//    bool                d_help;
//    bool                d_logout;
//    bool                d_submit = true;
//    size_t              d_uid;
//
//    std::string         d_uName;
//    std::string         d_pwd;
//    std::string         d_next;      // command entered in the 'cmd' input 
//                                    // field
//
//    std::string         d_reply;    // reply from the monitor
//
//    struct  MonitorIO;
//
//    friend struct Handler::MonitorIO;
//
//    template <typename Type>
//    friend MonitorIO &&operator<<(MonitorIO &&tmp, Type const &value);


//        size_t getUid();
//
//        void login();
//        void verifyUnPw();
//        void monitorCommand();
//        void showHtmlPage();
//        void logout();
//        void autoLogout();
//        void killed();
//
//        void incompleteUnPw();
//        void firstPage();
//        void unknownUser();    
//        void alreadyLoggedIn();
//        void monitorUnPwCheck();
//        void helpInfo();
//
//        MonitorIO monitorSubmit();            // .ih


#endif


