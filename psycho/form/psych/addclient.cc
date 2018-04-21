#include "psych.ih"

void Psych::addClient()
{
    uint32_t active= validClientData();

    d_client.push_back(
        PsychClient(
                ++d_lastClientID, 
                active, 
                stoul(d_cgi.param1("login0")),   // 0,//Tools::random(10, 99),
                d_cgi.param1("gender") == "M",
                d_cgi.param1("name"),
                d_cgi.param1("lastName"),
                d_cgi.param1("clEmail")
            )
    );

    if (active)
        activateClient(d_client.back());
}
