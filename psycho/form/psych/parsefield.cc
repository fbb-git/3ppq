#include "psych.ih"

//     <!-- field=1&field=2... -->

uint8_t Psych::parseField()
{
    string field = d_cgi.param1("field");
    if (field.empty())
        return 0;                       // field not specified

    uint8_t ret = 0;
    size_t pos = 0;

    while (true)
    {
        pos = field.find('=', pos);     
        if (pos == string::npos)        // no more values
            break;
        try
        {
            size_t value = stoul(field.substr(pos + 1));    // get the value
            if (
                value < 1 or value > Tools::MAX_PSYCH_FIELD or
                ((value - 1) & value)                       // value != 2^x
            )
                return ~0;                                  // illegal value

            ret |= value;                                   // set a bit
        }
        catch (...)                                         // not a number
        {
            return ~0;
        }
    }

    return ret != 0 ? ret : ~0;                             // there must be
                                                            // a value 
}           


