#include "Cube.hpp"
#include "Cross.hpp"
#include <iostream>

int main() {

  Cube::Cube myCube(false);

  myCube.moves("FFFRU");
  myCube.output();
  Cross::solveCross(myCube);
  myCube.output();
  return 0;
}
