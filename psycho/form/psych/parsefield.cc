#include "psych.ih"

//     <!-- field=1&field=2... -->

uint8_t Psych::parseField()
{
    uint8_t ret = 0;
    for (string const &value: d_cgi->param("field"))
    {
        g_log << "field = " << value << endl;
        ret |= stoul(value);
    }

    return ret;
}           


