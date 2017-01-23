all: Rubik

Rubik: Rubik.o Cube.o Cross.o Corners.o Edges.o OLL.o PLL.o
	g++ Rubik.o Cube.o Cross.o Corners.o Edges.o OLL.o PLL.o -o Rubik

Rubik.o: Rubik.cpp
	g++ -c Rubik.cpp

Cube.o: Cube.cpp Cube.hpp
	g++ -c Cube.cpp Cube.hpp

Cross.o: Cross.cpp Cross.hpp
	g++ -c Cross.cpp Cross.hpp

Corners.o: Corners.cpp Corners.hpp
	g++ -c Corners.cpp Corners.hpp

Edges.o: Edges.cpp Edges.hpp
	g++ -c Edges.cpp Edges.hpp

OLL.o: OLL.cpp OLL.hpp
	g++ -c OLL.cpp OLL.hpp

PLL.o: PLL.cpp PLL.hpp
	g++ -c PLL.cpp PLL.hpp


clean:
	rm *o Rubik
