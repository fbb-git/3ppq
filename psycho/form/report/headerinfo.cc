#include "report.ih"

string Report::headerInfo() const
{
    Psych psych;

    if (not psych.get(d_psychEmail))
        throw false;

    ostringstream out;
    
    time_t timeValue = d_from;
    tm tmValue{ *localtime(&timeValue) };

    out << 
R"_(    \makecell[l]{Naam cli\"ent:} 
\\
    \makecell[l]{Cli\"ent identificatie:} &
    \makecell[l]{)" <<  d_clientIdent   << R"(}
\\
    \makecell[l]{Afnamedatum:} &
    \makecell[l]{)_" << put_time(&tmValue, "%e %b %Y") << R"_(}
\\
    \makecell[l]{Psycholoog:} &
    \makecell[l]{)_" << psych.fullName() << "}\n";


    return out.str();

}
