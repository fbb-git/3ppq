#include "formhandler.ih"

void FormHandler::empty()       // called when the URI is unknown
{
    g_log << "empy() called with DOCUMENT_URI: `" <<
             d_cgi["DOCUMENT_URI"] << "' and state " << d_state << endl;
}
