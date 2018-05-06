#include "client.ih"

void Client::checkCompleted(WIPdata &wipData) const
{
    if (
        wipData.selfRatings().front() == 0    or
        wipData.metaRatings().front() == 0    or
        not otherRatingsCompleted(wipData)
    )
        return;

g_log << "data collection completed: writing " << g_options.data() << endl;

    LockStream data{ g_options.data() };

    data.open();
    LockGuard lg = data.lg();

    data.seekp(0, ios::end);
    
    data << wipData << endl;

    Report report{ wipData };
    report.generate();

    g_mailer.sendmail(
        wipData.psychEmail(),
        wipData.psychEmail(),
        "Resultaten 3ppq voor client " + wipData.clientIdent() + 
                                        " zijn beschikbaar",
        DollarText::replaceStream(
            g_options.mailDir() + "results", 
            {
                wipData.clientIdent(),                  // $0
            }
        )
    );
    
    wipData.remove();

g_log << "data stored" << endl;

}




