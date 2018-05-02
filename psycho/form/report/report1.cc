#include "report.ih"

Report::Report(WIPdata const &wipData)
:
    d_pidCid(wipData.pidCid()),
    d_csvName(g_options.tmpDir() + d_pidCid + ".csv"),
    d_from(wipData.startTime()),
    d_psychEmail(wipData.psychEmail())
{
    ofstream csv;
    Exception::open(csv, d_csvName);
    csv << wipData << endl;
}
