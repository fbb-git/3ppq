#set terminal pdf color size 60 cm, 40 cm
#set output "plot.pdf"

set terminal eps color  size 30 cm, 20 cm
set output "plot.eps"

#           L   R  B  T
set margins 15, 5, 7, 7

#set terminal png
#set output "plot.png"


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

set title "  "
# Results for SubjectName"

#   Legenda Font 
set key font ",24"

set xrange [0:7]
set yrange [-.5:1]

#set arrow from 1, -1 to 1, 1 nohead
#set arrow from 2, -1 to 2, 1 nohead
#set arrow from 3, -1 to 3, 1 nohead
#set arrow from 4, -1 to 4, 1 nohead
#set arrow from 5, -1 to 5, 1 nohead
#set label "Top1" at 1, 0.97 center


#set xtics font "Times-Roman,52" ("Agree." 1, "Consc." 2, "Activ." 3, "Neurot" 4, "Extrav" 5, "Alg." 6)
set xtics  font ",24" ("Extraversie." 1, "Mildheid" 2, "Ordelijkheid" 3, "Emot.Stab." 4, "Autonomie" 5)
set xtics offset 0,15

#set ytics font "Times-Roman,52" (" -1.0" -1, " -0.5" -.5, "0" 0, "0.5" 0.5, "1" 1)
set ytics font ",24" (" -1.0" -1, " -0.5" -.5, "0" 0, "0.5" 0.5, "1" 1)

# set for [i=1:9] linetype i dt i

#   lt  -   linetype
#   lc  -   linecolor
#   lw  -   linewidth
#   pt  -   pointtype
#   ps  -   pointsize

set style line 1 dt 1       lc rgb '#000000'   lw 1 pt 5 ps 1   # --- blue
set style line 2 dt " . "   lc rgb '#111111'   lw 1 pt 4 ps 1   # --- red
set style line 3 dt "-"   lc rgb '#222222'   lw 1 pt 3 ps 1   # --- green

# set style line 1 lt 1 lc rgb '#0060ad'  lw 2 pt 5 ps 1   # --- blue
# set style line 2 lt 2 lc rgb '#dd181f'  lw 2 pt 4 ps 1   # --- red
# set style line 3 lt 5 lc rgb '#18dd1f'  lw 3 pt 3 ps 1   # --- green


plot 'file.dat' index 0 with linespoints ls 1 title 'zelfperspectief',   \
     ''         index 1 with linespoints ls 2 title 'metaperspectief',   \
     ''         index 2 with linespoints ls 3 title 'anderperspectief'

# plot 'file.dat' index 0 with linespoints ls 1 title 'zelfperspectief'   at 0.14, 0.98,    \
#      ''         index 1 with linespoints ls 2 title 'metaperspectief'   at 0.34, 0.98,   \
#      ''         index 2 with linespoints ls 3 title 'anderperspectief'  at 0.56, 0.98


#plot 'file.dat' index 0 with linespoints ls 1 title {/Times=20 'self rating'}, \
#     ''         index 1 with linespoints ls 2 title 'peer rating', \
#     ''         index 2 with linespoints ls 3 title 'spouse rating' 


# pandoc -s -S article.html -o article.docx
