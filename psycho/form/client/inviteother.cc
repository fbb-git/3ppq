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
        "Verzoek namens " + wipData.clientName() + 
                                        " om een vragenlijst in te vullen",
        DollarText::replaceStream(
            g_options.mailDir() + "inviteother", 
            {
                wipData.clientName(),                   // $0
                wipData.clientLastName(),               // $1
                wipData.gender() ? "hem" : "haar",      // $2
                Tools::link(wipData.psychID(),          // $3
                            wipData.clientIdent(),
                            wipData.otherLogin(idx))
            }
        )
    );
}
