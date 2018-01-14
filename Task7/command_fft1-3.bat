set encoding utf8
set xl "f[Hz]"
set yl "Amplitude"
set xrange [0:8190]
set yrange [0:205.393]
set grid
set title "Apply FFT"
plot "spectrum1-3.plt" with lp
