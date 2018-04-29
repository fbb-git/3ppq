#include "gnuplot.ih"

void Gnuplot::plot() const
{
    string baseName{ d_ratings.psychID() + '.' + d_ratings.clientIdent() };

    TempStream tmpStream{ baseName };

    writeData(tmpStream);

    Process gnuplot{Process::CIN, "/usr/bin/gnuplot -" };
    
    gnuplot.start();

    gnuplot << R"(
set terminal pdf color size 30 cm, 20 cm
set output ")" << baseName << R"(.pdf"

set title "Results for )" << d_ratings.clientIdent() << R"("

set xrange [0:7]
set yrange [-1:1]

set arrow from 1, -1 to 1, 0.95 nohead
set label "Extraversie" at 1, 0.97 center

set arrow from 2, -1 to 2, 0.95 nohead
set label "Mildheid" at 2, 0.97 center

set arrow from 3, -1 to 3, 0.95 nohead
set label "Ordelijkheid" at 3, 0.97 center

set arrow from 4, -1 to 4, 0.95 nohead
set label "Emot.Stab." at 4, 0.97 center

set arrow from 5, -1 to 5, 0.95 nohead
set label "Autonomie" at 5, 0.97 center

set arrow from 6, -1 to 6, 0.95 nohead
set label "Algemeen" at 6, 0.97 center

set arrow from 0, 0 to 7, 0 nohead

set xtics ("Extraversie" 1, "Mildheid" 2, "Ordelijkheid" 3, "Emot.Stab." 4, \
            "Autonomie" 5, "Algemeen" 6)

set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 5 ps 1   # --- blue
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 1   # --- red
set style line 3 lc rgb '#18dd1f' lt 1 lw 2 pt 5 ps 1   # --- green


plot ')" << tmpStream.fileName() << 
   R"(' index 0 with linespoints ls 1 title 'zelfperspectief' at 0.95, 0.92,\
     '' index 1 with linespoints ls 2 title 'metaperspectief' at 0.95, 0.90 ,\
     '' index 2 with linespoints ls 3 title 'anderperspectief' at 0.95, 0.98
)" << eoi;
    
}

