#ifndef OLL_H
#define OLL_H

#include <iostream>
#include "Cube.hpp"
#include <iostream>

class OLL {

public:
  static void solveOLL(Cube&);
private:
  static int findState(Cube&); //Rotate U 4 times, check each cube state against file
  static int findEdges(Cube&);
  static void solveCase(Cube&, int);
  static int checkOLL(Cube&);
  static int checkEdges(Cube&);
};

#endif
