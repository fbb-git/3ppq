#include "psych.ih"

void Psych::getData()
try
{
    ifstream in;

    Exception::open(in, g_options.data());

    {
        LockGuard lg { d_data.lg() };
        if (not get())
            throw false;
    }

    requireEqual("email", d_eMail);

    FilterStreambuf filterStreambuf{ in, d_ID };

    istream ownData{ &filterStreambuf };

    cout << ownData.rdbuf();

    if (cout)
        return;

    cout.clear();
    throw -1;
}
catch (bool)
{
    throw;
}
catch (...)
{
    Tools::textHtml();

    d_display.out(
        "actions.h",
        {
            "<blockquote>Er zijn op dit moment geen beoordelingsdata "
                        "voor u beschikbaar</blockquote</blockquote>\n"
        }
    );
}



