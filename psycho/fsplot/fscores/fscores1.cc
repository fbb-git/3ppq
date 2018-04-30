#include "fscores.ih"

Fscores::Fscores(Dvector2 const &data)
:
    d_fscores( N_PERSPECTIVES, vector<double>(N_FACTORS) ),
    d_data(data)
{
    compute();
}
