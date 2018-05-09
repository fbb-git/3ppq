#include "psych.ih"

void Psych::pushClient()
{
    requireContents("ident");
    requireContents("name");
    requireContents("lastName");
    requireOneOf("gender",  "FM");
    requireOneOf("clEmail", "@");

    d_client.push_back(
        PsychClient(
                ++d_nClients,
                d_cgi->param1("gender") == "M",
                d_cgi->param1("ident"),
                d_cgi->param1("name"),
                d_cgi->param1("lastName"),
                d_cgi->param1("clEmail")
            )
    );
}
