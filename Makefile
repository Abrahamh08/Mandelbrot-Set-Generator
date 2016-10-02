.PHONY: windows linux clean

windows:
	-mkdir -p build
	x86_64-w64-mingw32-gcc src/main.c -L/usr/x86_64-w64-mingw32/lib -o build/Mandelbrot-Set-Generator.exe

linux:
	-mkdir -p build
	gcc src/main.c -O3 -o build/Mandelbrot-Set-Generator

clean:
	-rm -rf build
