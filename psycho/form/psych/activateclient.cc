#include "psych.ih"

void Psych::activateClient(PsychClient &client)
{
    client.activate();

    WIPdata wipData{ d_email, d_ID, client.id(), 
                     client.name() + ' ' + client.lastName(), 
                     client.gender() };

    g_mailer.sendmail(
        d_email,
        client.email(), 
        "Een uitnodiging van uw psycholoog",
        DollarText::replaceStream(
            g_options.mail() + "login0", 
            {
                client.genderText(),                                    // $0
                client.name(),                                          // $1
                client.lastName(),                                      // $2
                Tools::link(d_ID, client.id(), wipData.clientLogin()),  // $3
                d_email                                                 // $4
            }
        )
    );

        
}
