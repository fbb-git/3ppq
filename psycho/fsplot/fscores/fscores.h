#ifndef INCLUDED_FSCORES_
#define INCLUDED_FSCORES_

#include <vector>

#include "../values/values.h"

struct Fscores: public Values
{
    typedef std::vector< std::vector<double> > Dvector2;

    private:
        Dvector2 d_fscores;
    
        static double s_weights[N_FACTORS][N_QUESTIONS];
    
        Dvector2 const &d_data;

    public:
        Fscores(Dvector2 const &data);

        Dvector2 const &scores() const;
        Dvector2 table() const;

    private:
        void compute();
};
        
inline Fscores::Dvector2 const &Fscores::scores() const
{
    return d_fscores;
}

#endif


