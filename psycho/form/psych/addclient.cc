#include "psych.ih"

void Psych::addClient()
{
    g_log << "Add client ID " << d_lastClientID + 1 << endl;

    uint32_t active= validClientData();

    d_client.push_back(
        PsychClient(
                ++d_lastClientID, 
                active, 
                Tools::random(10, 99),
                d_cgi.param1("gender") == "M",
                d_cgi.param1("name"),
                d_cgi.param1("lastName"),
                d_cgi.param1("clEmail")
            )
    );

g_log << "LOGIN CODE = " << d_client.back().login0() << endl;

    if (active)
        activateClient(d_client.back());
}
