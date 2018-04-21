#include "psych.ih"

void Psych::clientPage()
try
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    
        string request = d_cgi.param1("request");

//g_log << "clientpage request = `" << request << '\'' << endl;

        if (request == "add")
            addClient();
        else if (request == "update")
            updateClient();
        else if (request == "remove")
            removeClient();

        d_data.update(emailKey(), toString());
    }

    ostringstream out;                          // construct the variables
    out << setw(7) << ' ' << "var nextID = " << d_lastClientID + 1 << ";\n" <<
           setw(7) << ' ' << "var login0 = '';";
    string clientVars = out.str();

    string clientArray;
    string clientSelect;

                                        // any defined clients?
    if (d_client.size())                // then create the <select> section
        infoClient(&clientArray, &clientSelect);  

//g_log << "start display: vars = " << clientVars << endl;

    d_display.append("email");
    d_display.out(
        g_options.html() + "clientpage.h",
        {
            clientArray,
            clientVars,
            clientSelect
        }
    );
}
catch (bool invalid)
{
    homePage();
}

