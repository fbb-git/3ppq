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





