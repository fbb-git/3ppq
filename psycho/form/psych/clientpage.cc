#include "psych.ih"

void Psych::clientPage()
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    
        string request = d_cgi.param1("request");
    
        if (request == "add")
            addClient();
        else if (request == "update")
            updateClient();
    }

    string clientArray;
    string clientVars;
    string clientSelect;

                                        // any defined clients?
    if (d_client.size())                // then create the <select> section
        infoClient(&clientArray, &clientVars, &clientSelect);  

    

    d_display.append("email");
    d_display.append("request", "");
    d_display.out(
        g_options.html() + "clientPage.h"
        {
            d_name,
            d_lastName,
            d_email,
            to_string(d_field)
        }
    );
}
