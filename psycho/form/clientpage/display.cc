#include "clientpage.ih"

    // return true if infoClient -> buildClientArray has modified clients'
    // data 
bool ClientPage::display(Info const &info, string const &eMail)
{
    ostringstream out;                          // construct the variables

    string clientArray;
    string clientSelect;
                                        // any defined clients?
    if (d_clients.size())                // then create the <select> section
        infoClient(&clientArray, &clientSelect);  

    d_display.out(
        "clientpage.h",
        {
            clientArray,
            clientSelect,
            "<tr class=darkrow><td colspan=2>\n" + 
                s_erase + info.submitActions + "\n"
            "</td></tr>",
            R"_(
<input type='hidden' name='email' value=')_" + eMail + R"_('>
<input type='hidden' name='show' value=')_" +
                to_string(info.clientIdx) + "'>\n",
            reportHyperlink(info.clientIdx)
        }
    );

    return not d_deactivated.empty();
}

