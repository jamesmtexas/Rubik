#include "PLL.hpp"
#include "Cube.hpp"
#include <iostream>

void PLL::solvePLL(Cube &cube) {
  adjustUFace(cube);
  while (!checkCorners(cube)) {
    solveCorners(cube);
    adjustUFace(cube);
  }

  while (!checkEdges(cube)) {
    solveEdges(cube);
  }
}

void PLL::adjustUFace(Cube &cube) {
  while (cube.cubies[2][5] != 5 || cube.cubies[0][2] != 2) {
    cube.moves("U");
  }
}

void PLL::solveEdges(Cube &cube) {
  if (cube.cubies[1][2] == 5 && cube.cubies[1][3] == 2 && cube.cubies[1][4] == 4 && cube.cubies[1][5] == 3) {
    cube.moves("RRURURRRUUURRRUUURRRURRR");
  }
  else if (cube.cubies[1][2] == 3 && cube.cubies[1][3] == 5 && cube.cubies[1][4] == 4 && cube.cubies[1][5] == 2) {
    cube.moves("RUUURURURUUURRRUUURR");
  }
  else if (cube.cubies[1][2] == 4 && cube.cubies[1][3] == 5 && cube.cubies[1][4] == 2 && cube.cubies[1][5] == 3) {
    cube.moves("RRLLDRRLLUURRLLDRRLL");
  }
  else if (cube.cubies[1][2] == 3 && cube.cubies[1][3] == 2 && cube.cubies[1][4] == 5 && cube.cubies[1][5] == 4) {
    cube.moves("URRRUUURUUURURUUURRRURURRUUURRRU");
  }
  else {
    cube.moves("RRURURRRUUURRRUUURRRURRR");
    adjustUFace(cube);
    cube.moves("RRLLDRRLLUURRLLDRRLL");
    cube.moves("RRURURRRUUURRRUUURRRURRR");
    adjustUFace(cube);
  }
}

void PLL::solveCorners(Cube &cube) {
  if (cube.cubies[2][2] == 4 && cube.cubies[0][3] == 5 && cube.cubies[2][3] == 2
  && cube.cubies[0][4] == 3 && cube.cubies[2][4] == 3 && cube.cubies[0][5] == 4) {
    cube.moves("RRRFRRRBBRFFFRRRBBRR");
  }
  else if (cube.cubies[2][2] == 4 && cube.cubies[0][3] == 5 && cube.cubies[2][3] == 3
  && cube.cubies[0][4] == 4 && cube.cubies[2][4] == 2 && cube.cubies[0][5] == 3) {
    cube.moves("RBBBRRRFRBRRRFFLLLBLFLLLBBBL");
  }
  else {
    cube.moves("RRRFRRRBBRFFFRRRBBRR");
  }
}

int PLL::checkCorners(Cube &cube) {
  if (cube.cubies[0][2] != 2 || cube.cubies[2][2] != 2 || cube.cubies[0][3] != 3 || cube.cubies[2][3] != 3 || cube.cubies[0][4] != 4 || cube.cubies[2][4] != 4 || cube.cubies[0][5] != 5 || cube.cubies[2][5] != 5) {
    return 0;
  }
  else
    return 1;
}

int PLL::checkEdges(Cube &cube) {
    if (cube.cubies[1][2] == 2 && cube.cubies[1][3] == 3 && cube.cubies[1][4] == 4 && cube.cubies[1][5] == 5) {
      return 1;
    }
    else {
      return 0;
    }
}
