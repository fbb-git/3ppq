#include "psych.ih"

void Psych::activateClient(PsychClient &client)
{
    client.activate();

    WIPdata wipData{ d_email, d_ID, client.id(), 
                     client.name() + ' ' + client.lastName(), 
                     client.gender() };

    string psychName{ d_name + ' ' + d_lastName };
 
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
                Tools::link(d_ID, client.id(), wipData.clientLogin()),  // $3
            }
        )
    );

        
}
