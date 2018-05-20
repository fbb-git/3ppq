#include "clientpage.ih"

string ClientPage::reportHyperlink(size_t idx) const
{
    return idx >= d_clients.size() || not d_reportExists[idx] ? 
            ""
        :
            R"_(<a href="/report.html" onclick="report()_" +
                to_string(idx)                           +
            R"_()">rapport</a>)_" + '\n';
}
