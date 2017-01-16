#include "Cross.hpp"
#include "Cube.hpp"

void Cross::solveCross(Cube &cube) {
  while (Cross::checkCross(cube)) {
    Cross:solveEdge(cube);
  }
}

int Cross::checkCross(Cube &cube) { //must check if in correct position as well
  if (!cube.cubies[1][0] && !cube.cubies[3][0] && !cube.cubies[5][0] && !cube.cubies[7][0])
    return 0;
  else
    return -1;
}

void Cross::solveEdge(Cube &cube) {

  //Check edges on all sides --- don't forget, white can be in wrong position on the bottom
  for (int side=0; side<6; ++side) {
    for (int edge = 1; edge<9; edge+=2) {
      if (cube.cubies[edge][side] == 0) {
        //Solve edge
        switch (side) {


          case 1: {//White edge on top
            if (edge == 1) { //orange side
              switch (cube.cubies[1][4]) {
                case 2://red
                  cube.moves("UUFF");
                  break;
                case 3://green
                  cube.moves("URR");
                  break;
                case 4:
                  cube.moves("BB");
                  break;
                case 5:
                  cube.moves("UUULL");
                  break;
              }
            }
            else if (edge == 3) {//Blue side
              switch (cube.cubies[1][5]) {
                case 2:
                  cube.moves("UUUFF");
                  break;
                case 3://green
                  cube.moves("UURR");
                  break;
                case 4:
                  cube.moves("UBB");
                  break;
                case 5:
                  cube.moves("LL");
                  break;
              }
            }
            else if (edge == 5) {//green side
              switch(cube.cubies[1][3]) {
                  case 2://red
                    cube.moves("UFF");
                    break;
                  case 3:
                    cube.moves("RR");
                    break;
                  case 4:
                    cube.moves("UUUBB");
                    break;
                  case 5:
                    cube.moves("UULL");
                    break;
              }
            }
            else if (edge == 7) {//red side
              switch (cube.cubies[1][2]) {
                  case 2:
                    cube.moves("FF");
                    break;
                  case 3:
                    cube.moves("UUURR");
                    break;
                  case 4:
                    cube.moves("UUBB");
                    break;
                  case 5:
                    cube.moves("ULL");
                    break;
              }
            }
            break;
          }
          case 2: {//White edge on red side

            if (edge == 1) {//Yellow side
              switch(cube.cubies[7][1]) {
                case 2:
                  cube.moves("UUURRRFR");
                  break;
                case 3://green on top, white on red side
                  cube.moves("FRRRFFF");
                  break;
                case 4:
                  cube.moves("UUURBBBRRR");
                  break;
                case 5:
                  cube.moves("FFFLF");
                  break;
              }
            }
            else if (edge == 3) { //Colored edge on blue side
              switch(cube.cubies[5][5]) {
                case 2:
                  break;
                case 3:
                  break;
                case 4:
                  break;
                case 5:
                  break;

              }
            }
            else if (edge == 5) { //check color on green side
              switch(cube.cubies[3][3]) {
              case 2:
                break;
              case 3:
                break;
              case 4:
                break;
              case 5:
                break;
              }
            }
            else if (edge == 7) { //check white side
              switch (cube.cubies[1][0]) {
              case 2:
                break;
              case 3:
                break;
              case 4:
                break;
              case 5:
                break;
              }
            }

            break;
          }
          case 3: //White edge on green side
            break;
          case 4: //White edge on orange side
            break;
          case 5: //White edge on blue side
            break;
        }
      }
    }
  }

}
