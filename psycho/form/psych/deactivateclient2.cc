#include "psych.ih"

void Psych::deactivateClient(WIPdata const &wipData)
{
    string key = Tools::md5hash(wipData.psychEmail());

    if (not get(key))
    {
        g_log << "Psych::deactivate2: cannot retrieve data for psych. " <<
                    wipData.psychEmail() << endl;
        return;
    }

    string const &clientIdent = wipData.clientIdent();

    for (PsychClient &client: d_client)
    {
        if (client.ident() == clientIdent)
        {
            client.deactivate();

            d_data.update(key, toString());
            return;
        }            
    }
}
