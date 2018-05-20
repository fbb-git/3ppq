#include "report.ih"

Report::Report(char const *pidCid, char const *psychEmail)
:
    d_pidCid(pidCid),
    d_pathPrefix(g_options.tmpDir() + d_pidCid + '.'),

    d_csvPath(d_pathPrefix      + "csv"),

    d_fScores(d_pathPrefix      + "fscores"),

    d_gnuplotInput(d_pathPrefix + "gp"),
    d_gnuplotData(d_pathPrefix  + "dat"),

    d_gnuplotEps(d_pathPrefix   + "eps"),

    d_latexInput(d_pathPrefix   + "latex"),
    d_dviFile(d_pathPrefix      + "dvi"),
    d_pdfFile(g_options.reportsDir() + d_pidCid + ".pdf"),

    d_clientIdent(d_pidCid.substr(d_pidCid.find('.') + 1)),
    d_from(0),
    d_psychEmail(psychEmail)
{}






