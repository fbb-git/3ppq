#include "fscores.ih"

Fscores::Fscores(Dvector2 const &data)
:
    d_fscores(Tools::N_PERSPECTIVES, vector<double>(Tools::N_FACTORS) ),
    d_data(data)
{
    compute();
}
