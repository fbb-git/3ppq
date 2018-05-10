#include "report.ih"

string Report::headerInfo() const
{
    Psych psych;

    if (not psych.get(Tools::md5hash(d_psychEmail)))
        throw false;

    ostringstream out;
    
    time_t timeValue = d_from;
    tm tmValue{ *localtime(&timeValue) };

    out << 
R"_1_(    \makecell[l]{Naam cli\"ent:} 
\\
    \makecell[l]{Cli\"ent identificatie:} &
    \makecell[l]{)_1_" <<  d_clientIdent   << R"_2_(}
\\
    \makecell[l]{Afnamedatum:} &
    \makecell[l]{)_2_" << put_time(&tmValue, "%e %b %Y") << R"_3_(}
\\
    \makecell[l]{Psycholoog:} &
    \makecell[l]{)_3_" << psych.fullName() << "}\n";

    return out.str();
}
