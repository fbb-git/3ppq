#include "report.ih"

void Report::generate() const
{
    fsplot();
    latex();
    dvipdf();
}
