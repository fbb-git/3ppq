#include "psych.ih"

void Psych::inviteClient(PsychClient &client)
{
    g_log << "activateClient starts" << endl;

    client.activate();

    WIPdata wipData{ d_email, d_ID, client.id(), 
                     client.name() + ' ' + client.lastName(), 
                     client.gender() };

    string psychName{ d_name + ' ' + d_lastName };

    string link =  Tools::link(d_ID, client.id(), wipData.clientLogin());
    g_log << "activateClient: link = " << link << endl;

    g_mailer.sendmail(
        d_email,
        client.email(), 
        "Verzoek namens " + psychName + "om een vragenlijst in te vullen",
        DollarText::replaceStream(
            g_options.mail() + "activateclient", 
            {
                client.genderText(),                                    // $0
                client.name() + ' ' + client.lastName(),                // $1
                psychName,                                              // $2
                link,  // $3
            }
        )
    );

        
}
