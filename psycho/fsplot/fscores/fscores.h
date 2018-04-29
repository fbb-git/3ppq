#ifndef INCLUDED_FSCORES_
#define INCLUDED_FSCORES_

#include <vector>

#include "../values/values.h"

class Fscores: private Values
{
    typedef std::vector< std::vector<double> > Dvector2;

    static double s_weights[N_FACTORS][N_QUESTIONS];

    Dvector2 const &d_data;

    public:
        Fscores(Dvector2 const &data);
        Dvector2 compute() const;

    private:
};
        
#endif
