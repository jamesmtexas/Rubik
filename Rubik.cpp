#include "Cube.hpp"
#include "Cross.hpp"
#include <iostream>

int main(int argc, char **argv) {

  Cube::Cube myCube(false);
  if (argc > 1) {
    std::string argString = std::string(argv[1]);
    myCube.moves(argString);
    Cross::solveCross(myCube);
  }
  return 0;
}
