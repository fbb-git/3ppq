#include "formhandler.ih"

FormHandler::FormHandler(char const *progname, char const *basePath)
:
    d_progname(progname),
    d_options(basePath),                    // defines all required 
                                            // filenames (like 'log')
                                            // under 'basePath'
//    d_in(d_options.fromMonitor()),
//    d_toMonitorFd(d_options.toMonitorFd()),
//    d_lockPath(d_options.toMonitor()),
//    d_out(d_lockPath),

    d_cgi(false)                            // do not escape received info
                                            // do not do Content-type...

//    d_help(d_cgi.param1("help") == "1"),
//    d_logout(d_cgi.param1("logout") == "1"),
//    d_uid(getUid()),
//    d_uName(d_cgi.param1("uname")),
//    d_pwd(d_cgi.param1("pwd")),
//    d_next(d_cgi.param1("next"))

{
    g_log.open(d_options.log());

    try                                 // if no state parameter is available
    {                                   // the default is used.
        d_state = static_cast<Action>(stoul(d_cgi.param1("state")));
    }
    catch (...)
    {}

    g_log << "FormHandler starts" << endl;

    Display::setBase(d_options.base() + "formhandler/");

    cout << R"(
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="content-type" content="text/html;
    charset=windows-1252">
    <style></style>
)";

}






