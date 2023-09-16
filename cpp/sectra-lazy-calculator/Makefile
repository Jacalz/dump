build:
	g++ src/main.cpp src/commands.cpp src/calculator.cpp src/register.cpp -o calculator -g

optimized:
	g++ src/main.cpp src/commands.cpp src/calculator.cpp src/register.cpp -o calculator -O3 -march=native

run: build
	./calculator

gdb: build
	gdb ./calculator

clean:
	rm calculator