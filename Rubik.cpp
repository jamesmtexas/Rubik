#include "Cube.hpp"
#include "Cross.hpp"
#include "Corners.hpp"
#include "Edges.hpp"
#include "OLL.hpp"
#include "PLL.hpp"
#include <iostream>

std::string format(std::string);

int main(int argc, char **argv) {

  Cube::Cube myCube(false);
  if (argc > 1) {
    std::string argString = std::string(argv[1]);
    std::string scramble = format(argString);
    std::cout << "Scramble: ";
    myCube.moves(scramble);
    Cross::solveCross(myCube);
    Corners::solveCorners(myCube);
    Edges::solveEdges(myCube);
    OLL::solveOLL(myCube);
    PLL::solvePLL(myCube);
    myCube.output();
  }
  return 0;
}

std::string format(std::string s) {
  std::string formatted;

  for (int i=0; i<s.length(); ++i) {
    if (s[i] == '\'') {
      formatted += s[i-1];
      formatted += s[i-1];
    }
    else if (s[i] == '2') {
      formatted += s[i-1];
    }
    else {
      formatted += s[i];
    }
  }

  return formatted;

}
