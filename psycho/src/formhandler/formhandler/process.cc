#include "formhandler.ih"

void FormHandler::process()
{
    g_log << "Starting FormHandler::process" << endl;

    void (FormHandler::**handler)() = s_psychoStates;

//        src.find("/psychologist.shtml") != string::npos ?   s_psychoStates :
//        src.find("/client.shtml") != string::npos ?         s_psychoStates :
//                                                            &s_empty;


        // when more URIs are used, use a map to select the appropriate
        // handler. 

    setState(handler);                                  // find the FSA state

    (this->*handler[d_state]) ();    // Initial state is START
}







