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
    
    data << wipData;

//    Report report{ wipData };
//    report.generate();

    Psych psych;
    if (not psych.get(Tools::md5hash(wipData.psychEmail())))
        throw false;

    psych.deactivateClient(wipData);

    g_mailer.sendmail(
        wipData.psychEmail(),
        wipData.psychEmail(),
        "Resultaten 3ppq voor client " + wipData.clientIdent() + 
                                        " zijn beschikbaar",
        DollarText::replaceStream(
            g_options.mailDir() + "results", 
            {
                psych.fullName(),
                wipData.clientIdent(),                  // $1
            }
        )
    );
    
    for (char const *name: 
                    Glob{ g_options.tmpDir() + wipData.pidCid() + ".*" } )
        unlink(name);
    
    wipData.remove();

g_log << "data stored" << endl;

}




