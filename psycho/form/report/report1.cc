#include "report.ih"

Report::Report(WIPdata const &wipData)
:
    d_psychEmail(wipData.psychEmail()),
    d_path(wipData.path())
{
}
