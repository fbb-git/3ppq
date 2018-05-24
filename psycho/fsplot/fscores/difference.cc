#include "fscores.ih"

// static
void Fscores::difference(Dvector2 &ret, size_t dest, 
                         size_t left, size_t right)
{
    for (size_t factor = 0; factor != Tools::N_FACTORS; ++factor)
        ret[factor][dest] = ret[factor][left] - ret[factor][right];
}
