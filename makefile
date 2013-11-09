default:
	g++ ./src/*.cpp `pkg-config gtkmm-3.0 --cflags --libs gtksourceviewmm-3.0` -llua -ldl -lm
	./a.out

debug:
	g++ ./src/*.cpp -g `pkg-config gtkmm-3.0 --cflags --libs gtksourceviewmm-3.0` -llua -ldl -lm
	nemiver a.out

bindbuffer:
	lua ../QuickBind/QuickBind.lua ./src/Buffer.h
run:
	./a.out
