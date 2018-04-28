#include "psych.ih"

void Psych::displayClientPage(DisplayInfo const &displayInfo)
{
    ostringstream out;                          // construct the variables

    string clientArray;
    string clientSelect;

                                        // any defined clients?
    if (d_client.size())                // then create the <select> section
        infoClient(&clientArray, &clientSelect);  

    d_display.out(
        "clientpage.h",
        {
            clientArray,
            clientSelect,
            "<tr class=darkrow><td colspan=2>\n" + 
                s_erase + displayInfo.submitActions + "\n"
            "</td></tr>",
            R"(
<input type='hidden' name='email' value=')" + d_email + R"('>
<input type='hidden' name='show' value=')" +
                to_string(displayInfo.clientIdx) + "'>\n"
        }
    );
}
