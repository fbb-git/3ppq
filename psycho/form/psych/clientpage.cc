#include "psych.ih"

void Psych::clientPage()
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    }

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
