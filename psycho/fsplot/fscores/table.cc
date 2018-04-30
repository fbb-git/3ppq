    #include "fscores.ih"

Fscores::Dvector2 Fscores::table() const
{
    Dvector2 ret(N_FACTORS, vector<double>(REPORT_COLUMNS));

    for (size_t factor = 0; factor != N_FACTORS; ++factor)
    {
        for (size_t type = 0; type != N_PERSPECTIVES; ++type)
            ret[factor][type] = d_fscores[type][factor];

        for (size_t left = 0; left != N_PERSPECTIVES; ++left)
        {
            for (size_t right = left + 1; right != N_PERSPECTIVES; ++right)
                ret[factor][N_PERSPECTIVES + left] = 
                                ret[factor][left] - ret[factor][right];
        }
    }

    return ret;
}
