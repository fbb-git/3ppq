#include "psych.ih"

void Psych::updateClient()
{
    uint32_t active = validClientData(); // input fm the form is valid

    auto clientIter = existingClient();

    g_log << "Updateclient ID " << clientIter->id() << ' ' << active << endl;

    if (active != 0 && clientIter->active() == 0)
        activateClient(*clientIter);

    clientIter->update(d_cgi.param1("name"), d_cgi.param1("lastName"), 
                       d_cgi.param1("clEmail"));
}
