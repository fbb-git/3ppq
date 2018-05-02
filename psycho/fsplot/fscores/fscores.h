#ifndef INCLUDED_FSCORES_
#define INCLUDED_FSCORES_

#include "../../support/types/types.h"
#include "../values/values.h"

class Fscores: public Values
{
    Dvector2 d_fscores;

    static double s_weights[N_FACTORS][N_QUESTIONS];

    Dvector2 const &d_data;

    public:
        Fscores(Dvector2 const &data);

        Dvector2 const &scores() const;
        Dvector2 table() const;             // table of FACTORS x REPORTCOLS

    private:
        void compute();
};
        
inline Dvector2 const &Fscores::scores() const
{
    return d_fscores;
}

#endif


