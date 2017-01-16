#include "Cross.hpp"
#include "Cube.hpp"

void Cross::solveCross(Cube cube) {
  while (!Cross::checkCross(cube)) {
    Cross:solveEdge(cube);
  }
}

int Cross::checkCross(Cube cube) {
  if (!cube.cubies[1][0] && !cube.cubies[3][0] && !cube.cubies[5][0] && !cube.cubies[7][0])
    return 0;
  else
    return -1;
}

void Cross::solveEdge(Cube cube) {

  //Check edges on all sides but white
  for (int side=1; side<6; ++side) {
    for (int edge = 1; edge<9; edge+=2) {
      if (cube.cubies[edge][side] == 0) {
        //Solve edge
        switch (side) {


          case 1: //White edge on top
            if (edge == 1) { //orange side
              switch (cube.cubies[1][4]) {
                case 2://red
                  cube.U(2);
                  cube.F(2);
                  break;
                case 3://green
                  cube.U(1);
                  cube.R(2);
                  break;
                case 4:
                  cube.B(2);
                  break;
                case 5:
                  cube.U(3);
                  cube.L(2);
                  break;
              }
            }
            else if (edge == 3) {//Blue side
              switch (cube.cubies[1][5]) {
                case 2:
                  cube.U(3);
                  cube.F(2);
                  break;
                case 3://green
                  cube.U(2);
                  cube.R(2);
                  break;
                case 4:
                  cube.U(1);
                  cube.B(2);
                  break;
                case 5:
                  cube.L(2);
                  break;
              }
            }
            else if (edge == 5) {//green side
              switch(cube.cubies[1][3]) {
                  case 2://red
                    cube.U(1);
                    cube.F(2);
                    break;
                  case 3:
                    cube.R(2);
                    break;
                  case 4:
                    cube.U(3);
                    cube.B(2);
                    break;
                  case 5:
                    cube.U(2);
                    cube.L(2);
                    break;
              }
            }
            else if (edge == 7) {//red side
              switch (cube.cubies[1][2]) {
                  case 2:
                    cube.F(2);
                    break;
                  case 3:
                    cube.U(3);
                    cube.R(2);
                    break;
                  case 4:
                    cube.U(2);
                    cube.B(2);
                    break;
                  case 5:
                    cube.U(1);
                    cube.L(2);
                    break;
              }
            }
            break;

          case 2: //White edge on red side
            break;
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
