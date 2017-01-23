#include "Cube.hpp"
#include "Edges.hpp"
#include <iostream>



void Edges::solveEdges(Cube &cube) {

  while (!checkEdges(cube)) {
    solveEdge(cube);
  }
}

void Edges::solveEdge(Cube &cube) {
  if (cube.cubies[1][1] != 1 && cube.cubies[1][4] != 1) {
    if (cube.cubies[1][1] == 2) {
      if (cube.cubies[1][4] == 3) {
        cube.moves("URRRUUURRRUUURRRURUR");
      }
      else if (cube.cubies[1][4] == 5) {
        cube.moves("BUBUBUUUBBBUUUBBB");
      }
    }
    else if (cube.cubies[1][1] == 3) {
      if (cube.cubies[1][4] == 4) {
        cube.moves("BBBUUUBBBUUUBBBUBUB");
      }
      else if (cube.cubies[1][4] == 2) {
        cube.moves("UUFUFUFUUUFFFUUUFFF");
      }
    }
    else if (cube.cubies[1][1] == 4) {
      if (cube.cubies[1][4] == 5) {
        cube.moves("UUULLLUUULLLUUULLLULUL");
      }
      else if (cube.cubies[1][4] == 3) {
        cube.moves("BBBUUUBBBUUUBBBUBUB");
      }
    }
    else if (cube.cubies[1][1] == 5) {
      if (cube.cubies[1][4] == 2) {
        cube.moves("UUFFFUUUFFFUUUFFFUFUF");
      }
      else if (cube.cubies[1][4] == 4) {
        cube.moves("LLLUUULLLUUULLLULUL");
      }
    }
  }

  else if (cube.cubies[5][1] != 1 && cube.cubies[1][3] != 1) {
    if (cube.cubies[5][1] == 2) {
      if (cube.cubies[1][3] == 3) {
        cube.moves("RRRUUURRRUUURRRURUR");
      }
      else if (cube.cubies[1][3] == 5) {
        cube.moves("UULULULUUULLLUUULLL");
      }
    }
    else if (cube.cubies[5][1] == 3) {
      if (cube.cubies[1][3] == 4) {
        cube.moves("UUUBBBUUUBBBUUUBBBUBUB");
      }
      else if (cube.cubies[1][3] == 2) {
        cube.moves("UFUFUFUUUFFFUUUFFF");
      }
    }
    else if (cube.cubies[5][1] == 4) {
      if (cube.cubies[1][3] == 5) {
        cube.moves("UULLLUUULLLUUULLLULUL");
      }
      else if (cube.cubies[1][3] == 3) {
        cube.moves("RURURUUURRRUUURRR");
      }
    }
    else if (cube.cubies[5][1] == 5) {
      if (cube.cubies[1][3] == 2) {
        cube.moves("UFFFUUUFFFUUUFFFUFUF");
      }
      else if (cube.cubies[1][3] == 4) {
        cube.moves("UUUBUBUBUUUBBBUUUBBB");
      }
    }
  }
  else if (cube.cubies[7][1] != 1 && cube.cubies[1][2] != 1) {
    if (cube.cubies[7][1] == 2) {
      if (cube.cubies[1][2] == 3) {
        cube.moves("UUURRRUUURRRUUURRRURUR");
      }
      else if (cube.cubies[1][2] == 5) {
        cube.moves("ULULULUUULLLUUULLL");
      }
    }
    else if (cube.cubies[7][1] == 3) {
      if (cube.cubies[1][2] == 4) {
        cube.moves("UUBBBUUUBBBUUUBBBUBUB");
      }
      else if (cube.cubies[1][2] == 2) {
        cube.moves("FUFUFUUUFFFUUUFFF");
      }
    }
    else if (cube.cubies[7][1] == 4) {
      if (cube.cubies[1][2] == 5) {
        cube.moves("ULLLUUULLLUUULLLULUL");
      }
      else if (cube.cubies[1][2] == 3) {
        cube.moves("UUURURURUUURRRUUURRR");
      }
    }
    else if (cube.cubies[7][1] == 5) {
      if (cube.cubies[1][2] == 2) {
        cube.moves("FFFUUUFFFUUUFFFUFUF");
      }
      else if (cube.cubies[1][2] == 4) {
        cube.moves("UUBUBUBUUUBBBUUUBBB");
      }
    }
  }
  else if (cube.cubies[3][1] != 1 && cube.cubies[1][5] != 1) {
    if (cube.cubies[3][1] == 2) {
      if (cube.cubies[1][5] == 3) {
        cube.moves("UURRRUUURRRUUURRRURUR");
      }
      else if (cube.cubies[1][5] == 5) {
        cube.moves("LULULUUULLLUUULLL");
      }
    }
    else if (cube.cubies[3][1] == 3) {
      if (cube.cubies[1][5] == 4) {
        cube.moves("UBBBUUUBBBUUUBBBUBUB");
      }
      else if (cube.cubies[1][5] == 2) {
        cube.moves("UUUFUFUFUUUFFFUUUFFF");
      }
    }
    else if (cube.cubies[3][1] == 4) {
      if (cube.cubies[1][5] == 5) {
        cube.moves("LLLUUULLLUUULLLULUL");
      }
      else if (cube.cubies[1][5] == 3) {
        cube.moves("UURURURUUURRRUUURRR");
      }
    }
    else if (cube.cubies[3][1] == 5) {
      if (cube.cubies[1][5] == 2) {
        cube.moves("UUUFFFUUUFFFUUUFFFUFUF");
      }
      else if (cube.cubies[1][5] == 4) {
        cube.moves("UBUBUBUUUBBBUUUBBB");
      }
    }
  }
  else if (cube.cubies[3][2] != 2 || cube.cubies[5][5] != 5) {
    cube.moves("LULULUUULLLUUULLL");
  }
  else if (cube.cubies[5][2] != 2 || cube.cubies[3][3] != 3) {
    cube.moves("FUFUFUUUFFFUUUFFF");
  }
  else if (cube.cubies[5][3] != 3 || cube.cubies[3][4] != 4) {
    cube.moves("RURURUUURRRUUURRR");
  }
  else if (cube.cubies[5][4] != 4 || cube.cubies[3][5] != 5) {
    cube.moves("BUBUBUUUBBBUUUBBB");
  }


}

int Edges::checkEdges(Cube &cube) {
  if (cube.cubies[3][2] != 2 || cube.cubies[5][2] != 2)
    return 0;
  else if (cube.cubies[3][3] != 3 || cube.cubies[5][3] != 3)
    return 0;
  else if (cube.cubies[3][4] != 4 || cube.cubies[5][4] != 4)
    return 0;
  else if (cube.cubies[3][5] != 5 || cube.cubies[5][5] != 5)
    return 0;
  else
    return 1;
}
