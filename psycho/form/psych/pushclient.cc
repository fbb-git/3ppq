#include "psych.ih"

void Psych::pushClient()
{
//    uint32_t active= validClientData();

    d_client.push_back(
        PsychClient(
                stoul(d_cgi.param1("ID")),
                d_cgi.param1("gender") == "M",
                d_cgi.param1("name"),
                d_cgi.param1("lastName"),
                d_cgi.param1("clEmail")
            )
    );
}
