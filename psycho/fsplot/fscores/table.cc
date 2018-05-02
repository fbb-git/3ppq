#include "fscores.ih"

Dvector2 Fscores::table() const
{
    Dvector2 ret(Tools::N_FACTORS, vector<double>(Tools::REPORT_COLUMNS));

    for (size_t factor = 0; factor != Tools::N_FACTORS; ++factor)
    {
        for (size_t type = 0; type != Tools::N_PERSPECTIVES; ++type)
            ret[factor][type] = d_fscores[type][factor];

        for (size_t left = 0; left != Tools::N_PERSPECTIVES; ++left)
        {
            for (
                size_t right = left + 1; 
                    right != Tools::N_PERSPECTIVES; 
                        ++right
            )
                ret[factor][Tools::N_PERSPECTIVES + left] = 
                                ret[factor][left] - ret[factor][right];
        }
    }

    return ret;
}
