#include "client.ih"

void Client::quest()
{
    string action = d_cgi.param1("action");

    int nr = Tools::valueOr(d_cgi.param1("nr"), -2);

    g_log << "Client::quest: " << action << ", nr = " << nr << endl;

//    if (action == "terug")
//    {
//        g_log << "resetting " << (nr - 1) << " to " << (nr - 2) << endl;
//        nr -= 2;
//    }
    
    if (nr < -1 or nr >= d_nQuestions)               // illegal number
    {
        Display{ g_options.html() + "homepage" };
        return;
    }

    if (nr >= d_nQuestions)
    {
        Display{ g_options.html() + "thanks" };
        return;
    }

    // process received answer if nr != -1

    ++nr;

    StrVector sv 
                { 
                    to_string(nr + 1),
                    "bent u",
                    d_lines[nr]
                };

    StrVector endLines {
            Tools::passParam(d_cgi, "id"),
            Tools::passParam("nr", to_string(nr)),
        };

    if (nr != 0)
        endLines.push_back(
R"(
    <input value="terug" name="action" type="submit">
)"
        );
    
    Display {
        endLines,
        g_options.html() + "quest", 
        &sv
    };
}





