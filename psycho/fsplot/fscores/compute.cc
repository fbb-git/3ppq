#include "fscores.ih"

void Fscores::compute()
{
        // note: s_weights is a n N_FACTORS * N_QUESTIONS matrix: 
        //       so it has been transposed, allowing row-wise handling of
        //       of the factor weights.

    for (size_t row = 0, nRows = d_data.size(); row != nRows; ++row)
    {
        for (size_t col = 0; col != Tools::N_FACTORS; ++col)
            d_fscores[row][col] = 
                inner_product(d_data[row].begin(), d_data[row].end(),
                              s_weights[col], 0.0);
    }
}
