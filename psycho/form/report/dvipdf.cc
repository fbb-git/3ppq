#include "report.ih"

void Report::dvipdf() const
{
    Tools::childProcess(g_config.findKeyTail("dvipdf:") + ' ' + 
                            d_dviFile + ' ' + d_pdfFile);
}


