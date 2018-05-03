set terminal pdf color  size 30 cm, 20 cm

# /home/frank/git/psycho/src/psycho/website/tmp/1.es.eps: path of the .eps file to create. 
set output "1.pdf"

unset border
unset ytics

#           L   R  B  T
set margins 15, 5, 7, 7

set xrange [0:6]
set yrange [-.5:.9]

# set arrow from 0, -.57 to 0,.82 lw 3 heads

# set arrow from 1, -.01 to 1, .01 nohead
# set arrow from 2, -.01 to 2, .01 nohead
# set arrow from 3, -.01 to 3, .01 nohead
# set arrow from 4, -.01 to 4, .01 nohead
# set arrow from 5, -.01 to 5, .01 nohead

set arrow from 0, 0 to 6, 0 nohead
set arrow from 1, -.01 to 1, .01 nohead

#   Legenda Font 
set key font ",24"

set xtics  font ",24" ("Extraversie." 1, "Mildheid" 2, "Ordelijkheid" 3, \
                       "Emot.Stab." 4, "Autonomie" 5)

set label "Extraversie" at 1, .85 center font ",24" 
set label "Introversie" at 1,-.45 center font ",24" 

set arrow from 0,.8 to 0,.9 lw 2 nohead
set label '\~'    at 0,.8  center font ",20" 
set label '\~'    at 0,.785 center font ",20" 
set arrow from 0,-.385 to 0,.785 lw 2 nohead
set label '\~'    at 0,-.385 center font ",20" 
set label '\~'    at 0,-.4  center font ",20" 
set arrow from 0,-.4 to 0,-.5 lw 2 nohead


set arrow from 6,.8 to 6,.9 lw 2 nohead
set label '\~'    at 6,.8  center font ",20" 
set label '\~'    at 6,.785 center font ",20" 
set arrow from 6,-.385 to 6,.785 lw 2 nohead
set label '\~'    at 6,-.385 center font ",20" 
set label '\~'    at 6,-.4  center font ",20" 
set arrow from 6,-.4 to 6,-.5 lw 2 nohead

set arrow from 0,.9 to 6,.9 lw 2 nohead
set arrow from 0,-.5 to 6,-.5 lw 2 nohead


# set xtics offset 0,18

unset xtics

# set ytics font ",24" (" -0.5" -.5, "0" 0, "0.5" .5, "0.75" .75)

#   lt  -   linetype
#   lc  -   linecolor
#   lw  -   linewidth
#   pt  -   pointtype
#   ps  -   pointsize

set style line 1 dt 1   lc rgb '#000000'    lw 6 pt 5 ps 1
set style line 2 dt 2   lc rgb '#000000'    lw 8 pt 2 ps 1
set style line 3 dt 3   lc rgb '#000000'    lw 8 pt 2 ps 1

# /home/frank/git/psycho/src/psycho/website/tmp/1.es.dat: path of the data file. 
plot '/home/frank/git/psycho/src/psycho/website/tmp/1.es.dat' index 0 with linespoints ls 3 title 'zelfperspectief' at 0.29,0.91,\
     ''   index 1 with linespoints ls 2 title 'metaperspectief' at 0.56,0.91,\
     ''   index 2 with linespoints ls 1 title 'anderperspectief' at 0.82,0.91



