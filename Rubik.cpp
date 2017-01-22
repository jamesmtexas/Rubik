#include "Cube.hpp"
#include "Cross.hpp"
#include "Corners.hpp"
#include "Edges.hpp"
#include "OLL.hpp"
#include "PLL.hpp"
#include <iostream>

int main(int argc, char **argv) {

  Cube::Cube myCube(false);
  if (argc > 1) {
    std::string argString = std::string(argv[1]);
    std::cout << "Scramble: ";
    myCube.moves(argString);
    Cross::solveCross(myCube);
    Corners::solveCorners(myCube);
    Edges::solveEdges(myCube);
    OLL::solveOLL(myCube);
    //PLL::solvePLL(myCube);
    myCube.output();
  }
  return 0;
}
