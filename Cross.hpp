#ifndef CROSS_H
#define CROSS_H

#include "Cube.hpp"

class Cross {
public:
  static void solveCross(Cube&);
  static int checkCross(Cube&);
  static void solveEdge(Cube&);
};

#endif
