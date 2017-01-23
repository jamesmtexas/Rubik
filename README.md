# Rubik
Rubik's cube solver 

~1500 sloc

This is an automatic Rubik's cube solver in C++. 
Input is received through stdin.
The output is the sequence of moves to solve the given scrambled cube.

Example compilation:
	g++ Rubik.cpp Cube.cpp Cube.hpp Cross.cpp Cross.hpp Corners.cpp Corners.hpp Edges.cpp Edges.hpp OLL.cpp OLL.hpp PLL.cpp PLL.hpp

Example usage:
cat scrambled.txt | ./Rubik

Example scramble file:
F2 L' D2 F2 R B2 U2 B2 D2 L R F U' F2 L2 D' B F R D2
F2 R2 D' R2 D2 U' L2 U2 F U2 B2 L D' F' R D2 F' D' R'
B U2 L2 R2 F2 L2 B' D2 B R' B2 F' R2 B L' U R2 F2 U'
D2 R2 F' R2 F' D2 U2 F' R2 F2 U' R' B2 D' B' D2 U' F2 R U
B2 R2 B U2 R' U R D R B D' R F2 L B2 L2 F2 U2 L
L2 F U2 F D2 B2 L2 R2 U' L' B2 R' D L' D B' L2 F2
D2 F2 L2 B2 L U2 L' R' F2 D2 F R2 U R' F' R' F2 L' R2 F
D2 L2 D2 L' U2 R2 F2 R' D2 U' L2 F D' R2 F R B D R2 U2
L' D2 L' F2 R' D2 R' D' R' F' R' B2 D' B' R2 D2 B2 L
U' R2 U R2 D L2 D L2 B2 D' F' D' R D2 L D' B2 L' R2 U R2
F' L2 R2 B' D2 R2 B R2 B' R2 F' U' B D U R' F' L2 U B' D
U2 R F2 R2 B2 L F2 R2 D R2 D2 B2 F U2 R' F L2 F' D2
L2 U R' B L U L2 D' R' F D R2 F2 B2 D' F2 D' B2 L2
L2 U2 B' U2 R2 B U2 F L2 B2 R U F2 L2 R F' L' D2 U B
D2 F' R2 B2 F' L2 F' L' F D L' F' U F' L2 U' L U'
