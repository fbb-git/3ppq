#include "report.ih"

Report::Report(WIPdata const &wipData)
:
    d_pidCid(wipData.pidCid()),
    d_pathPrefix(g_options.tmpDir() + d_pidCid + '.'),

    d_csvPath(d_pathPrefix      + "csv"),

    d_fScores(d_pathPrefix      + "fscores"),

    d_gnuplotInput(d_pathPrefix + "gp"),
    d_gnuplotData(d_pathPrefix  + "dat"),

    d_gnuplotEps(d_pathPrefix   + "eps"),

    d_latexInput(d_pathPrefix   + "latex"),
    d_dviFile(d_pathPrefix      + "dvi"),
    d_pdfFile(g_options.reportsDir() + to_string(wipData.psychID()) + '/' +
                                                        d_pidCid + ".pdf"),

    d_clientIdent(wipData.clientIdent()),
    d_from(wipData.startTime()),
    d_psychEmail(wipData.psychEmail())
{
    ofstream csv;
    Exception::open(csv, d_csvPath);            // produced CSV file
    csv << wipData << endl;
}





