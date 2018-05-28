#include "report.ih"

void Report::generate()
{
    g_log << "generating report (background)" << endl;
    fork();
}
