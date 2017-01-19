#include "Cube.hpp"
#include "Edges.hpp"


void Edges::solveEdges(Cube &cube) {

  while (!checkEdges(cube)) {
      solveEdge(cube);
  }
}

void Edges::solveEdge(Cube &cube) {
  if (cube.cubies[1][1] != 1 && cube.cubies[1][4] != 1) {
    if (cube.cubies[1][1] == 2) {
      if (cube.cubies[1][4] == 3) {
        cube.moves("URRRUUURRRUUURRRURUR");
      }
      else if (cube.cubies[1][4] == 5) {
        cube.moves("UUULUUULUUULULLLULLL");
      }
    }
    else if (cube.cubies[1][1] == 3) {
      if (cube.cubies[1][4] == 4) {
        cube.moves("BBBUUUBBBUUUBBBUBUB");
      }
      else if (cube.cubies[1][4] == 2) {
        cube.moves("UUFUFUFUUUFFFUUUFFF");
      }
    }
    else if (cube.cubies[1][1] == 4) {
      if (cube.cubies[1][4] == 5) {
        cube.moves("UUULLLUUULLLUUULLLULUL");
      }
      else if (cube.cubies[1][4] == 3) {
        cube.moves("BBBUUUBBBUUUBBBUBUB");
      }
    }
    else if (cube.cubies[1][1] == 5) {
      if (cube.cubies[1][4] == 2) {
        cube.moves("UUFFFUUUFFFUUUFFFUFUF");
      }
      else if (cube.cubies[1][4] == 4) {
        cube.moves("LLLUUULLLUUULLLULUL");
      }
    }
  }

  else if (cube.cubies[5][1] != 1 && cube.cubies[1][3] != 1) {
    
  }
  else if (cube.cubies[7][1] != 1 && cube.cubies[1][2] != 1) {

  }
  else if (cube.cubies[3][1] != 1 && cube.cubies[1][5] != 1) {

  }
  else {
    if (cube.cubies[3][2] != 2 || cube.cubies[5][2] != 2 || cube.cubies[3][4] != 4 || cube.cubies[5][4] != 4) {
      cube.moves("RURURUUURRRUUURRR");
    }
  }

}

int Edges::checkEdges(Cube &cube) {
  if (cube.cubies[3][2] == 1 || cube.cubies[5][2] == 1)
    return 0;
  else if (cube.cubies[3][3] == 1 || cube.cubies[5][3] == 1)
    return 0;
  else if (cube.cubies[3][4] == 1 || cube.cubies[5][4] == 1)
    return 0;
  else if (cube.cubies[3][5] == 1 || cube.cubies[5][5] == 1)
    return 0;
  else
    return 1;
}
