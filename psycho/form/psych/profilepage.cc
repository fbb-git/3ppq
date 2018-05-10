#include "psych.ih"

void Psych::profilePage()
{
    {
        LockGuard lg { d_data.lg() };
        if (not get())
            return;
    }

    requireEqual("email", d_eMail); // all forms must have the psych's e-mail

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
