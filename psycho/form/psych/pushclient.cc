#include "psych.ih"

bool Psych::pushClient()
{
    requireContents("ident");
    requireContents("name");
    requireContents("lastName");
    requireOneOf("gender",  "FM");
    requireOneOf("clEmail", "@");

    string const &ident = d_cgi->param1("ident");

    for( PsychClient const &client: d_client)
    {
        if (client.ident() == ident)
            return false;
    }
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
    return true;
}
