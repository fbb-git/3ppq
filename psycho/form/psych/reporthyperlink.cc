#include "psych.ih"

string Psych::reportHyperlink(size_t idx) const
{
    return idx >= d_client.size() ? 
            ""
        :
            R"(<a href="/report.html" onclick="report()" +
                to_string(idx)                           +
            R"_()">rapport</a>)_" + '\n';
}
