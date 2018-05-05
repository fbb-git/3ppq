#include "gnuplot.ih"

int Gnuplot::plot(char const *gnuplotIn) const
{
    Process process{Process::NONE, // IGNORE_COUT_CERR,  
                    g_config.findKeyTail("gnuplot:")  + ' ' + gnuplotIn };
 
    process.start();

    return process.waitForChild();
}

