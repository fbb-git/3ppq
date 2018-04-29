#include "gnuplot.ih"

Gnuplot::Gnuplot(Ratings const &ratings, Dvector2 &&fscores)
:
    d_ratings(ratings),
    d_fscores(move(fscores))
{}
