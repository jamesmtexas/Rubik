#ifndef PLL_H
#define PLL_H

#include "Cube.hpp"

class PLL {

public:
  static void solvePLL(Cube &);
  static void adjustUFace(Cube &);
  static void solveCorners(Cube &);
  static int checkCorners(Cube &);
  static int checkEdges(Cube &);
  static void solveEdges(Cube &);
};

#endif
