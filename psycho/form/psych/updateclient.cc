#include "psych.ih"

ClientPage::Info Psych::updateClient()
{
    uint16_t idx = validClientIdx();

    if (idx == d_client.size())
        throw Tools::NO_CLIENT;

    requireContents("ident");
    requireContents("name");
    requireContents("lastName");
    requireOneOf("clEmail", "@");

    d_client[idx].update(d_cgi->param1("ident"), 
                         d_cgi->param1("name"), d_cgi->param1("lastName"), 
                         d_cgi->param1("clEmail"));

    return showClient();
}











