//#include "psych.ih"
//
//    // return true if infoClient -> buildClientArray has modified clients'
//    // data 
//bool Psych::displayClientPage(DisplayInfo const &displayInfo)
//{
//    ostringstream out;                          // construct the variables
//
//    string clientArray;
//    string clientSelect;
//
//    vector<bool> reportExists;
//
//    bool clientsChanged = false;
//
//                                        // any defined clients?
//    if (d_client.size())                // then create the <select> section
//        clientsChanged = 
//            infoClient(&clientArray, &clientSelect, reportExists);  
//
//    d_display.out(
//        "clientpage.h",
//        {
//            clientArray,
//            clientSelect,
//            "<tr class=darkrow><td colspan=2>\n" + 
//                s_erase + displayInfo.submitActions + "\n"
//            "</td></tr>",
//            R"_(
//<input type='hidden' name='email' value=')_" + d_eMail + R"_('>
//<input type='hidden' name='show' value=')_" +
//                to_string(displayInfo.clientIdx) + "'>\n",
//            reportHyperlink(reportExists, displayInfo.clientIdx)
//        }
//    );
//
//    return clientsChanged;
//}

