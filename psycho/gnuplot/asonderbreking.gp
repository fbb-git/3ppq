set terminal pdf color  size 30 cm, 20 cm

# /home/frank/git/psycho/src/psycho/website/tmp/1.es.eps: path of the .eps file to create. 
set output "1.pdf"

unset border
unset xtics
unset ytics

#           L   R   B  T
set margins 15, 15, 7, 7

set xrange [0:6]
set yrange [-.6:.8]

#   Legenda Font 
set key font ",24"

# Factor labels, U and D
set label "Extravert" at 1, .75 center font ",24" 
set label "Mild"      at 2, .75 center font ",24" 
set label "Ordelijk"  at 3, .75 center font ",24" 
set label "Stabiel"   at 4, .75 center font ",24" 
set label "Autonoom"  at 5, .75 center font ",24" 

set label "Introvert" at 1,-.55 center font ",24" 
set label "Hard"      at 2,-.55 center font ",24" 
set label "Ordeloos"  at 3,-.55 center font ",24" 
set label "Labiel"    at 4,-.55 center font ",24" 
set label "Volgzaam"  at 5,-.55 center font ",24" 

# Vertical axes, L and R
set arrow from 0,.7 to 0,.8 lw 2 nohead
set label '\~'    at 0,.7  center font ",20" 
set label '\~'    at 0,.685 center font ",20" 
set arrow from 0,-.485 to 0,.685 lw 2 nohead
set label '\~'    at 0,-.485 center font ",20" 
set label '\~'    at 0,-.5  center font ",20" 
set arrow from 0,-.5 to 0,-.6 lw 2 nohead

set arrow from 6,.7 to 6,.8 lw 2 nohead
set label '\~'    at 6,.7  center font ",20" 
set label '\~'    at 6,.685 center font ",20" 
set arrow from 6,-.485 to 6,.685 lw 2 nohead
set label '\~'    at 6,-.485 center font ",20" 
set label '\~'    at 6,-.5  center font ",20" 
set arrow from 6,-.5 to 6,-.6 lw 2 nohead

# 0-value line
set arrow from 0,0 to 6,0   lw 2 nohead

# Horizontal axis, U and D
set arrow from 0,.8 to 6,.8 lw 2 nohead
set arrow from 0,-.6 to 6,-.6 lw 2 nohead

# Numbers alongside L, R axes
set label '-1.0'  at  -.05,-.6 right font ",20" 
set label '-0.4'  at  -.05,-.4 right font ",20" 
set label '-0.2'  at  -.05,-.2 right font ",20" 
set label '0'     at  -.05,0   right font ",20" 
set label '0.2'   at  -.05,.2  right font ",20" 
set label '0.4'   at  -.05,.4  right font ",20" 
set label '0.6'   at  -.05,.6  right font ",20" 
set label '1.0'   at  -.05,.8  right font ",20" 

set label '-1.0'  at  6.05,-.6 left  font ",20" 
set label '-0.4'  at  6.05,-.4 left  font ",20" 
set label '-0.2'  at  6.05,-.2 left  font ",20" 
set label '0'     at  6.05,0   left  font ",20" 
set label '0.2'   at  6.05,.2  left  font ",20" 
set label '0.4'   at  6.05,.4  left  font ",20" 
set label '0.6'   at  6.05,.6  left  font ",20" 
set label '1.0'   at  6.05,.8  left  font ",20" 

#   Tic marks in L, R vertical axes
set arrow from  -.025,-.4  to .025,-.4   lw 2 nohead
set arrow from  -.025,-.2  to .025,-.2   lw 2 nohead
set arrow from  -.025, .2  to .025, .2   lw 2 nohead
set arrow from  -.025, .4  to .025, .4   lw 2 nohead
set arrow from  -.025, .6  to .025, .6   lw 2 nohead

set arrow from   5.975,-.4  to 6.025,-.4   lw 2 nohead
set arrow from   5.975,-.2  to 6.025,-.2   lw 2 nohead
set arrow from   5.975, .2  to 6.025, .2   lw 2 nohead
set arrow from   5.975, .4  to 6.025, .4   lw 2 nohead
set arrow from   5.975, .6  to 6.025, .6   lw 2 nohead


#   lt  -   linetype
#   lc  -   linecolor
#   lw  -   linewidth
#   pt  -   pointtype
#   ps  -   pointsize

set style line 1 dt 1   lc rgb '#000000'    lw 6 pt 5 ps 1
set style line 2 dt 2   lc rgb '#000000'    lw 8 pt 2 ps 1
set style line 3 dt 3   lc rgb '#000000'    lw 8 pt 2 ps 1

# /home/frank/git/psycho/src/psycho/website/tmp/1.es.dat: path of the data file. 
plot '/home/frank/git/psycho/src/psycho/website/tmp/1.es.dat' \
          index 0 with linespoints ls 3 title 'zelfperspectief' at 0.26,0.91,\
     ''   index 1 with linespoints ls 2 title 'metaperspectief' at 0.53,0.91,\
     ''   index 2 with linespoints ls 1 title 'anderperspectief' at 0.79,0.91



