#include "psych.ih"

void Psych::profilePage()
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    }

    d_display.append("email");

    d_display.out(
        "profile.h",
        {
            d_name,
            d_lastName,
            d_eMail,
            to_string(d_field),
            to_string(d_nip)
        }
    );
}
