#include "fscores.ih"

Fscores::Fscores(Dvector2 const &data)
:
    d_fscores(Tools::N_PERSPECTIVES, vector<double>(Tools::N_FACTORS) ),
    d_data(data)
{
                        // transpose the f-scores matrix.
    for (size_t row = 0; row != Tools::N_QUESTIONS; ++row)
    {
        for (size_t col = 0; col != Tools::N_FACTORS; ++col)
            s_weights[col][row] = s_orgWeights[row][col];
    }

    compute();
}
