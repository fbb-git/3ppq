#include "psych.ih"

void Psych::clientPage()
{
    DisplayInfo displayInfo = { s_add + s_addActive };

//g_log << "clientpage request = `" << d_cgi->param1("request") << "', "
//        "valid client data: active: " <<  d_cgi->param1("active") << 
//           ", form-email: " <<  d_cgi->param1("clEmail") << 
//           ", email: " << d_cgi->param1("email") << 
//           ", ID: " << d_cgi->param1("ident") << 
//           ", gender: " << d_cgi->param1("gender") << 
//           ", name: " << d_cgi->param1("name") << 
//           ", lastname: " << d_cgi->param1("lastName") << endl;

    {
        LockGuard lg { d_data.lg() };
        if (not get())
            throw Tools::NO_PSYCH;

                                    // all forms must have the psych's e-mail
        requireEqual("email", d_eMail); 
    
        displayInfo.clientIdx = d_client.size();

        if (                        // determine the function to perform
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

