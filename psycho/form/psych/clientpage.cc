#include "psych.ih"

void Psych::clientPage()
try
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    
        string request = d_cgi.param1("request");

g_log << "clientpage request = `" << request << '\'' << endl;

        if (request == "add")
            addClient();
        else if (request == "update")
            updateClient();
        else if (request == "remove")
            removeClient();

        d_data.update(emailKey(), toString());
    }

    ostringstream out;                          // construct the variables

    string clientArray;
    string clientSelect;

                                        // any defined clients?
    if (d_client.size())                // then create the <select> section
        infoClient(&clientArray, &clientSelect);  

    d_display.append("email");
    d_display.out(
        "clientpage.h",
        {
            clientArray,
            clientSelect
        }
    );
}
catch (bool invalid)
{
    d_display.homePage();
}

