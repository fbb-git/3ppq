#ifndef INCLUDED_FSCORES_
#define INCLUDED_FSCORES_

#include "../../support/types/types.h"
#include "../../support/tools/tools.h"

class Fscores
{
    Dvector2 d_fscores;

    static double s_weights[Tools::N_FACTORS][Tools::N_QUESTIONS];

    Dvector2 const &d_data;

    public:
        Fscores(Dvector2 const &data);

        Dvector2 const &scores() const;
        Dvector2 table() const;             // table of FACTORS x REPORTCOLS

    private:
        void compute();
        static void difference(Dvector2 &ret, size_t dest, 
                               size_t left, size_t right);
};
        
inline Dvector2 const &Fscores::scores() const
{
    return d_fscores;
}

#endif


