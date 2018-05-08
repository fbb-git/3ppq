#include "psych.ih"

void Psych::clientPage()
{
    DisplayInfo displayInfo = { s_add + s_addActive };

g_log << "clientpage request = `" << d_cgi->param1("request") << '\'' << endl;

    {
        LockGuard lg { d_data.lg() };
        if (not get())
            throw false;
    
        displayInfo.clientIdx = d_client.size();

        if (
            auto iter = s_clientPageRequest.find(d_cgi->param1("request")); 
            iter != s_clientPageRequest.end()
        )
        {
            displayInfo = (this->*iter->second)();    
                                        // add, addActive, deactivate, show, 
                                        // update, updateActive, remove, 

            d_data.update(emailKey(), toString());
        }
    }                                    

g_log << "clientpage idx = " << displayInfo.clientIdx <<  endl;


    displayClientPage(displayInfo);

}

