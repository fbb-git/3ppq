#include "psych.ih"

void Psych::inviteClient(PsychClient &client)
{
    client.activate();

    WIPdata wipData{ d_eMail, d_ID, client.ident(), 
                     client.name() + ' ' + client.lastName(), 
                     client.gender() };

    string psychName{ d_name + ' ' + d_lastName };

    string link =  Tools::link(d_ID, client.ident(), wipData.clientLogin());
    Tools::debug() << "inviteClient: link = " << link << endl;

    g_mailer.sendmail(
        d_eMail,
        client.eMail(), 
        "Verzoek namens " + psychName + " om een vragenlijst in te vullen",
        DollarText::replaceStream(
            g_options.mailDir() + "activateclient", 
            {
                client.genderText(),                        // $0
                client.name() + ' ' + client.lastName(),    // $1
                psychName,                                  // $2
                link,                                       // $3
            }
        )
    );
}
