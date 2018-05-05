#include "report.ih"

void Report::writeLatexInputFile() const
{
    DollarText::replace(
                    d_latexInput, g_options.moldsDir() + "latex", 
                    { 
                        g_options.imagesDir() + "3ppqUL.eps",   // logo
                        headerInfo(),
                        d_gnuplotEps,
                        latexScoresTable()
                    }
                );
}
