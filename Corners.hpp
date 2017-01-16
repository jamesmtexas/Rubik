#ifndef CORNERS_H
#define CORNERS_H

#include "Cube.hpp"
#include "Cross.hpp"

class Corners {

public:
  static int checkCorners(Cube&);
  static void solveCorners(Cube&);
  static int checkBottomLayer(Cube &cube);

};

#endif
