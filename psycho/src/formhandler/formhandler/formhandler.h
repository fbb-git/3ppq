#ifndef INCLUDED_FORMHANDLER_
#define INCLUDED_FORMHANDLER_

// #include <condition_variable>
 
#include <string>

// #include <fstream>

#include <bobcat/cgi>

#include "../options/options.h"

class FormHandler
{
    enum Action
    {
        START,
        REQUEST,
//        VERIFY_UNPW,        
//        CMD,                
//        LOGOUT,
    };

    std::string         d_progname;
    Options             d_options;

//    std::ifstream       d_in;
//    int                 d_toMonitorFd;
//    std::string const  &d_lockPath;
//    std::ofstream       d_out;

    FBB::CGI            d_cgi;

    Action              d_state = START;
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
//    friend struct FormHandler::MonitorIO;
//
//    template <typename Type>
//    friend MonitorIO &&operator<<(MonitorIO &&tmp, Type const &value);

    static void (FormHandler::*s_psychoStates[])();
    static void (FormHandler::*s_clientStates[])();
    static void (FormHandler::*s_empty)();          // strange call from
                                                    // non-existing URI?

    public:
        FormHandler(char const *progname, char const *basePath);
        ~FormHandler();
        void process();

    private:
        void setState(void (FormHandler::**handler)());

        void empty();                           // e.g., wrong URI
        void psychoStart();
        void psychoRequest();

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


