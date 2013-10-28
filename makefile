default:
	g++ *.cpp `pkg-config gtkmm-3.0 --cflags --libs gtksourceviewmm-3.0` -llua -ldl -lm
	./a.out

run:
	./a.out
