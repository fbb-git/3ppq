#include "psych.ih"

void Psych::clientPage()
{
    ClientPage::Info info = { s_add + s_addActive };

//g_log << "clientpage request = `" << d_cgi->param1("request") << "', "
//        "valid client data: active: " <<  d_cgi->param1("active") << 
//           ", form-email: " <<  d_cgi->param1("clEmail") << 
//           ", email: " << d_cgi->param1("email") << 
//           ", ID: " << d_cgi->param1("ident") << 
//           ", gender: " << d_cgi->param1("gender") << 
//           ", name: " << d_cgi->param1("name") << 
//           ", lastname: " << d_cgi->param1("lastName") << endl;

    
    bool updated = false;
    LockGuard lg { d_data.lg() };
    if (not get())
        throw Tools::NO_PSYCH;

                                // all forms must have the psych's e-mail
    requireEqual("email", d_eMail); 

    info.clientIdx = d_client.size();

    if (                        // determine the function to perform
        auto iter = s_clientPageRequest.find(d_cgi->param1("request")); 
        iter != s_clientPageRequest.end()
    )
    {
        info = (this->*iter->second)();    
                                    // add, addActive, deactivate, show, 
                                    // update, updateActive, remove, 
        updated = true;
    }

g_log << "clientpage idx = " << info.clientIdx <<  endl;

    ClientPage page{ d_display, d_client, d_ID };

    if (page.display(info, d_eMail) or updated)
    {
        for (size_t idx: page.deactivated())
            d_client[idx].deactivate();

        d_data.update(emailKey(), toString());
    }

//FBB    if (displayClientPage(displayInfo) or updated)
//FBB        d_data.update(emailKey(), toString());
}










