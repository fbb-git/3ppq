#ifndef INCLUDED_GNUPLOT_
#define INCLUDED_GNUPLOT_

#include <vector>

#include "../../support/types/types.h"

#include "../values/values.h"

class Ratings;

class Gnuplot: public Values
{
    Ratings const &d_ratings;
    Dvector2 const &d_fscores;              // TYPES * N_FACTORS

    public:
        Gnuplot(Ratings const &ratings, Dvector2 const &fscores);
        int plot(char const *infile) const;
};
        
#endif
