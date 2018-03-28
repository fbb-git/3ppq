#include "formhandler.ih"

void FormHandler::process()
{
    g_log << "Starting FormHandler::process" << endl;

                                        // determine the sets of states to use
    void (FormHandler::**handler)() = 
        d_cgi["DOCUMENT_URI"] == "/psychologist.shtml"s ?   s_psychoStates :
        d_cgi["DOCUMENT_URI"] == "/client.shtml"s ?         s_psychoStates :
                                                           &s_empty;
        // when more URIs are used, use a map to select the appropriate
        // handler. 

    (this->*handler[d_state]) ();    // Initial state is START
}
