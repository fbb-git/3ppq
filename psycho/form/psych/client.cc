#include "psych.ih"

void Psych::client()
{
    LockGuard lg{ d_data.lg() };

    if (not get())              // retrieve psych data
        return;
   
    // show client data, modify / delete 

        // add client:
    d_client.resize(d_client.size() + 1);

    PsychClient &client = d_client.back();

    if (not client.set(d_cgi))
        return;

//    g_wip.add(client);
}
