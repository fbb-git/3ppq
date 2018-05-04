#include "report.ih"

string Report::headerInfo() const
{
    ostringstream out;
    
    time_t timeValue = d_from;
    tm tmValue{ *localtime(&timeValue) };

    out << 
R"(    \makecell[l]{Client identificatie:} &
    \makecell[l]{)" <<  d_clientIdent   << R"(}
\\
    \makecell[l]{Afnamedatum:} &
    \makecell[l]{)" << put_time(&tmValue, "%e %b %Y") << "}\n";

    return out.str();

// R"(}
// \\.
//     \makecell[l]{Psycholoog:} &
//     \makecell[l]{)" <<     << "}\n";

}
