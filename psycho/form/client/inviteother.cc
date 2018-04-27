#include "client.ih"

void Client::inviteOther(WIPdata const &wipData, size_t idx)
{
    g_log << "inviteOther: name: " << wipData.clientName() << 
            ", psych e-mail: " << wipData.psychEmail() << 
            ", hash: " << loginHash(wipData.otherLogin(idx)) <<
            endl;

    
            
    g_mailer.sendmail(
        wipData.psychEmail(),
        wipData.otherEmail(idx),
        "Verzoek tot deelname aan een psychologisch onderzoek",
        DollarText::replaceStream(
            g_options.mail() + "other", 
            {
                wipData.clientName(),                   // $0
                wipData.gender() ? "hem" : "haar",      // $1
                Tools::link(wipData.psychID(),          // $2
                            wipData.clientID(),
                            wipData.otherLogin(idx)), 
                wipData.psychEmail()                     // $3
            }
        )
    );
}
