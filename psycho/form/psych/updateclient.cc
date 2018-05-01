#include "psych.ih"

Psych::DisplayInfo Psych::updateClient()
{
//    uint32_t reqActive = validClientData(); // input fm the form is valid,
                                            // 'active' is time(0) if active
                                            // was specified
    uint16_t idx = validClientIdx();

    d_client[idx].update(d_cgi.param1("ident"), 
                         d_cgi.param1("name"), d_cgi.param1("lastName"), 
                         d_cgi.param1("clEmail"));

    return showClient();
}

//
//    g_log << "Updateclient ID " << clientIter->id() << ' ' << reqActive << 
//                                                                        endl;
//    if (clientIter->active() != 0)          // client active
//    {
//        if (not WIPdata::exists(d_ID, clientIter->id()))
//            clientIter->deactivate();               // #2   (see below)
//    }
//    else if (reqActive != 0)
//        activateClient(*clientIter);                // #3, #4
//    else
//        WIPdata::remove(d_ID, clientIter->id());    // #5
//











