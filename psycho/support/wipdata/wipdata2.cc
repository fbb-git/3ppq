#include "wipdata.ih"

WIPdata::WIPdata(string const &query)
{
    size_t dot = query.find('.');
    size_t equal = query.find('=', dot);

    if (equal == string::npos)          // invalid query
        throw false;

    d_psychID = stoul(query.substr(0, dot));
    ++dot;
    d_clientIdent = query.substr(dot, equal - dot);
}
