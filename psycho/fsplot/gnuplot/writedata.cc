#include "gnuplot.ih"

void Gnuplot::writeData(ostream &out) const
{
    for (size_t perspective = 0; perspective != N_PERSPECTIVES; ++perspective)
    {
        for (size_t factor = 0; factor != N_FACTORS; ++factor)
            out << (factor + 1) << ' ' << d_fscores[perspective][factor] << 
                                                                        '\n';

        out << "\n\n";
    }

    out.flush();            
}
