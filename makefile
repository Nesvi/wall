default:
	g++ *.cpp `pkg-config gtkmm-3.0 --cflags --libs gtksourceviewmm-3.0` -llua -ldl -lm
	./a.out

debug:
	g++ *.cpp -g `pkg-config gtkmm-3.0 --cflags --libs gtksourceviewmm-3.0` -llua -ldl -lm
	nemiver a.out

run:
	./a.out
