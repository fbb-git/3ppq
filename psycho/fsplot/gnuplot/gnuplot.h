#ifndef INCLUDED_GNUPLOT_
#define INCLUDED_GNUPLOT_

#include <vector>
#include <iosfwd>

#include "../values/values.h"

class Ratings;

class Gnuplot: private Values
{
    typedef std::vector< std::vector<double> > Dvector2;

    Ratings const &d_ratings;
    Dvector2 const &d_fscores;              // TYPES * N_FACTORS

    public:
        Gnuplot(Ratings const &ratings, Dvector2 const &fscores);
        void plot() const;

    private:

    void writeData(std::ostream &out) const;

};
        
#endif
