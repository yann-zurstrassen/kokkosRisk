set terminal pngcairo size 900,500 enhanced font "sans,11"
set output 'plot.png'

set title "Data Distribution & Trend"
set xlabel "Time (Days)"
set ylabel "Price of Petrol"

set yrange [1.840:1.860]
set format y "%.3f"

set grid dt 2 lc rgb "#cccccc"
set key top right

plot 'datafile.txt' using 1:2 with linespoints \
	lw 1.5 \
	pt 7 \
	ps 0.5 \
	lc rgb "#1f77b4" \
	title "Price of Oil Prediction"
