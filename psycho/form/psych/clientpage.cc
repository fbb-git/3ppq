#include "psych.ih"

void Psych::clientPage()
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    }

    string clientInfo;
    string clientSelect;
;
    if (d_client.size())                // any defined clients?
    {                                   // then create the <select> section
        infoClient(&clientInfo, &clientSelect);  

    

    d_display.append("email");

    d_display.out(
        g_options.html() + "client.h",
        {
            d_name,
            d_lastName,
            d_email,
            to_string(d_field)
        }
    );
}
