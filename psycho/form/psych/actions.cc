#include "psych.ih"

void Psych::actions()
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    }

    d_display.append("email");

    size_t action = Tools::valueOr(d_cgi.param1("action"), s_actionsSize);

g_log << "actions: " << action << endl;
    
    switch (action)
    {
        case 1:     // client.h
        break;

        case 2:     // data.h
        break;

        case 3:     // profile.h
            d_display.out(
                g_options.html() + "profile.h",
                {
                    d_name,
                    d_lastName,
                    d_email,
                    to_string(d_field)
                }
            );
        break;

        case 4:     // contact.h
        break;
    
        default:
            homePage();
        break;
    }
}
