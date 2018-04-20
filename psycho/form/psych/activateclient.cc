#include "psych.ih"

void Psych::activateClient(PsychClient &client)
{
    client.activate();
    LockStream wip{ g_options.wip() };      // access the wip stream

    WIPdata wipData{ d_ID, client.id(), client.login0() };

    {
        LockGuard lg { wip.lg() };              // lock the stream
        wip.open();                             // write the wip-data to file
        wip.seekp(0, ios::end);
        wipData.write(wip);                     // add to the end
    }

    g_mailer.sendmail(
        client.email(), 
        "Een uitnodiging van uw psycholoog",
        DollarText::replaceStream(
            g_options.mail() + "login0", 
            {
                client.genderText(),                // $0
                client.name(),                      // $1
                client.lastName(),                  // $2
                to_string(wipData.loginClient()),   // $3
                d_email                             // $4
            }
        )
    );

        
}
