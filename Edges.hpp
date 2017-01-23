#ifndef EDGES_H
#define EDGES_H

#include "Cube.hpp"

class Edges {

public:
  static void solveEdges(Cube &cube);
private:
  static void solveEdge(Cube &cube);
  static int checkEdges(Cube &cube);
};

#endif
