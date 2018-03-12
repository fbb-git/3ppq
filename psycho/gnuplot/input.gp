set terminal pdf color size 30 cm, 20 cm
set output "plot.pdf"

# sset title ’This is a plot of $y=\sin(x)$’    $...$: cursief
# set xlabel ’This is the $x$ axis’             onder de fig

# set ylabel ’This is\\the\\$y$ axis’           L-naast, \\ is newline
#                                               also use offsets, see 
#                                               'set ylabel' in the manual

# set key at x,y                                UR corner of plot-descriptions
# plot [0:6.28] [0:1] sin(x)                    convert: x en y range/steps

                                                # multiple plots: separated 
                                                # by commas
    # "file.dat" may contain data points: 
    # "file.dat" with linespoints will plot the data
# plot [-3.14:3.14] sin(x), x with lines, "file.dat"
# plot [0:6] "file.dat" with linespoints

set title "Results for SubjectName"

set xrange [0:6]
set yrange [-1:1]

set arrow from 1, -1 to 1, 0.95 nohead
set label "Top1" at 1, 0.97 center

set arrow from 2, -1 to 2, 0.95 nohead
set label "Top2" at 2, 0.97 center

set arrow from 3, -1 to 3, 0.95 nohead
set label "Top3" at 3, 0.97 center

set arrow from 4, -1 to 4, 0.95 nohead
set label "Top4" at 4, 0.97 center

set arrow from 5, -1 to 5, 0.95 nohead
set label "Top5" at 5, 0.97 center


set arrow from 0, 0 to 6, 0 nohead

set xtics ("Agree." 1, "Consc." 2, "Activ." 3, "Neurot" 4, "Extrav" 5)

set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 5 ps 1   # --- blue
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 1   # --- red
set style line 3 lc rgb '#18dd1f' lt 1 lw 2 pt 5 ps 1   # --- green


plot 'file.dat' index 0 with linespoints ls 1 title 'self rating', \
     ''         index 1 with linespoints ls 2 title 'peer rating',  \
     ''         index 2 with linespoints ls 3 title 'spouse rating'





