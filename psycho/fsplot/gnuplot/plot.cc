#include "gnuplot.ih"

int Gnuplot::plot(char const *gnuplotIn) const
{
    Process gnuplot{Process::NONE,  "/usr/bin/gnuplot "s  + gnuplotIn };
 
    gnuplot.start();

    return gnuplot.waitForChild();
}

