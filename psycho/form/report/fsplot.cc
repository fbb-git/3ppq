#include "report.ih"

void Report::fsplot() const
{
    DollarText::replace(d_gnuplotInput, 
                            g_options.moldsDir() + "gnuplot", 
                            { 
                                d_gnuplotEps, 
                                d_gnuplotData 
                            } 
                        );

    Tools::childProcess(
                            g_options.binDir() + "fsplot " +
                            d_csvPath       + ' ' +
                            d_gnuplotInput  + ' ' +
                            d_gnuplotData   + ' ' +
                            d_fScores
                        );
}


