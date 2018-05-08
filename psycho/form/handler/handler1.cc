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

    if (
        d_cgi.param1("state") != "report" ||
        d_cgi.param1("type") != "psych"
    )
        cout << 
"Content-type: text/html\r\n\r\n"
R"(
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="content-type" content="text/html; charset=windows-1252">
    <link rel="stylesheet" type="text/css" href="/css/3ppq.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
)";

}




//    d_in(d_options.fromMonitor()),
//    d_toMonitorFd(d_options.toMonitorFd()),
//    d_lockPath(d_options.toMonitor()),
//    d_out(d_lockPath),

//    d_help(d_cgi.param1("help") == "1"),
//    d_logout(d_cgi.param1("logout") == "1"),
//    d_uid(getUid()),
//    d_uName(d_cgi.param1("uname")),
//    d_pwd(d_cgi.param1("pwd")),
//    d_next(d_cgi.param1("next"))


//    try                                 // if no state parameter is available
//    {                                   // the default is used.
//        d_state = static_cast<Action>(stoul(d_cgi.param1("state")));
//    }
//    catch (...)
//    {}





