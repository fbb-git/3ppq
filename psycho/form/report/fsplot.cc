#include "report.ih"

void Report::fsplot()
{
    string const &mold = g_options.gnuplotMold();

    ofstream gnuplotIn{ d_gnuplotInput };
    ofstream plotData{ d_gnuplotData };

    DollarText::replace(gnuplotIn, mold, { d_gnuplotEps, d_gnuplotData } );

    string command =  g_options.binDir() + "fsplot " +
                        d_csvPath       + ' ' +
                        d_gnuplotInput  + ' ' +
                        d_gnuplotData   + ' ' +
                        d_fScores ;

    Process fsplot { Process::NONE, command };

    fsplot.start();

    if (fsplot.waitForChild() != 0)
    {
        g_log << "Command `" << command << "' failed" << endl;
        throw false;
    }
}


