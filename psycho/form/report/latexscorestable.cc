#include "report.ih"

string Report::latexScoresTable() const
{
    ifstream scores;
    Exception::open(scores, d_fScores);

    ostringstream latexScores;
    latexScores << scores.rdbuf();
    
    return latexScores.str();
}
