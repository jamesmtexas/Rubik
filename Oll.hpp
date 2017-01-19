#ifndef OLL_H
#define OLL_H

#include <iostream>
#include "Cube.hpp"
#include <iostream>

class OLL {

public:
  static int findState(Cube&); //Rotate U 4 times, check each cube state against file
  static void solveCase(Cube&, int);
  static void solveOLL(Cube&);
};

#endif
