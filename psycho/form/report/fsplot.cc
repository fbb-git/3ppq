#include "report.ih"

void Report::fsplot()
{
    string const &mold = g_options.gnuplotMold();

    string base { g_options.tmpDir() + d_pidCid };

    ofstream gnuplotIn{ base + ".gp" };
    ofstream plotData{ base + ".dat" };

    d_eps =  base + ".eps";
    d_scores = base + ".scores";

    DollarText::replace(gnuplotIn, mold, { d_eps, base + ".dat" } );

    Process fsplot { Process::NONE, 
                     g_options.binDir() + "fsplot " +   // call fsplot
                        d_csvName + ' ' +               // csv file
                        base + ".gp" + ' ' +    // gnuplot input file
                                                        // (writes d_eps)
                        base + ".dat" + ' ' +     // data for gnuplot
                        d_scores                        // scores table
            };

    fsplot.start();
    fsplot.waitForChild();
}


