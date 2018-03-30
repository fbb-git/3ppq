#include "handler.ih"

Handler::Handler(char const *basePath)
:
    d_options(basePath),                    // define all required 
                                            // filenames (like 'log')
                                            // under 'basePath'

    d_cgi(false)                            // do not escape received info
                                            // do not do Content-type...
{
    g_log.open(d_options.log());

    g_log << "Handler starts" << endl;

    Display::setBase(d_options.base() + "stubs/");

    cout << R"(
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="content-type" content="text/html; charset=windows-1252">
    <style></style>
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





