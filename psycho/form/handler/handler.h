#ifndef INCLUDED_HANDLER_
#define INCLUDED_HANDLER_

// #include <condition_variable>
 
#include <string>

// #include <fstream>

#include <bobcat/cgi>

#include "../../library/options/options.h"

class Handler
{
    std::string         d_progname;
    Options             d_options;

//    std::ifstream       d_in;
//    int                 d_toMonitorFd;
//    std::string const  &d_lockPath;
//    std::ofstream       d_out;

    FBB::CGI            d_cgi;

    std::string         d_state;
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

    static void (Handler::*s_psychoStates[])();
    static void (Handler::*s_clientStates[])();
    static void (Handler::*s_empty)();          // strange call from
                                                    // non-existing URI?

    public:
        Handler(char const *basePath);
        ~Handler();
        void process();

    private:
//        void setState(void (Handler::**handler)());

        void empty();                           // e.g., wrong URI
        void psychoStart();
        void psychoRequest();


        void logParams();

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
};

#endif


