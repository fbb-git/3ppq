#include "handler.ih"

Handler::Handler()
:
    d_cgi(false, 0),                        // do not escape received info
                                            // do not do Content-type...
    d_client(d_cgi),
    d_psych(d_cgi)
{
    g_log << "Handler starts: state = " << d_cgi.param1("state") <<
            ", type = " << d_cgi.param1("type") << endl;

    if (d_cgi.param1("type") == "psych")
    {
        string const &state = d_cgi.param1("state");
        if (state == "report" || state == "getData")    // states using 
            return;                                     // their own
    }                                                   // content-types 

    Tools::textHtml();
}





