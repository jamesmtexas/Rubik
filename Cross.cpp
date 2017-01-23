#include "Cross.hpp"
#include "Cube.hpp"
#include <iostream>

void Cross::solveCross(Cube &cube) {
  while (checkCross(cube)) {
    solveEdge(cube);
  }
}

int Cross::checkCross(Cube &cube) { //must check if in correct position as well
  if (!cube.cubies[1][0] && !cube.cubies[3][0] && !cube.cubies[5][0] && !cube.cubies[7][0] && cube.cubies[7][2] == 2 && cube.cubies[7][3] == 3 && cube.cubies[7][4] == 4 && cube.cubies[7][5] == 5) {
    return 0;
  }
  else
    return 1;
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
                  cube.moves("LDLLL");
                  break;
                case 3:
                  cube.moves("UUFUU");
                  break;
                case 4:
                  cube.moves("LLLULBB");
                  break;
                case 5:
                  cube.moves("L");
                  break;

              }
            }
            else if (edge == 5) { //check color on green side
              switch(cube.cubies[3][3]) {
              case 2:
                cube.moves("RRRDDDR");
                break;
              case 3:
                cube.moves("RRR");
                break;
              case 4:
                cube.moves("RUUURRRBB");
                break;
              case 5:
                cube.moves("RUURRRLL");
                break;
              }
            }
            else if (edge == 7) { //check white side
              switch (cube.cubies[1][0]) {
              case 2:
                cube.moves("FFFDRRRDDD");
                break;
              case 3:
                cube.moves("FFFRRR");
                break;
              case 4:
                cube.moves("FFUUURBBBRRR");
                break;
              case 5:
                cube.moves("FL");
                break;
              }
            }

            break;
          }
          case 3: //White edge on green side
            if (edge == 1) {//Yellow side
              switch(cube.cubies[5][1]) {
                case 2:
                  cube.moves("RRRFR");
                  break;
                case 3:
                  cube.moves("UFRRRFFF");
                  break;
                case 4:
                  cube.moves("RBBBRRR");
                  break;
                case 5:
                  cube.moves("UFFFLF");
                  break;
                }
              }
              else if (edge == 3) { //Colored edge on red side
                switch(cube.cubies[5][2]) {
                  case 2:
                    cube.moves("F");
                    break;
                  case 3:
                    cube.moves("FFFUUUFRR");
                    break;
                  case 4:
                    cube.moves("RRBBBRR");
                    break;
                  case 5:
                    cube.moves("FFFUFLL");
                    break;

                }
              }
              else if (edge == 5) { //check color on orange side
                switch(cube.cubies[3][4]) {
                  case 2:
                    cube.moves("RRFRR");
                    break;
                  case 3:
                    cube.moves("BUBBBRR");
                    break;
                  case 4:
                    cube.moves("BBB");
                    break;
                  case 5:
                    cube.moves("RRRUFFFLF");
                    break;
                }
              }
              else if (edge == 7) { //check white side
                switch (cube.cubies[5][0]) {
                  case 2:
                    cube.moves("RFRRR");
                    break;
                  case 3:
                    cube.moves("RRUFRRRFFF");
                    break;
                  case 4:
                    cube.moves("RRRBBBR");
                    break;
                  case 5:
                    cube.moves("RRUFFFLF");
                    break;
                }
              }
            break;
          case 4: //White edge on orange side
            if (edge == 1) {//Yellow side
              switch(cube.cubies[1][1]) {
                case 2:
                    cube.moves("URRRFR");
                    break;
                  case 3:
                    cube.moves("BBBRB");
                    break;
                  case 4:
                    cube.moves("URBBBRRR");
                    break;
                  case 5:
                    cube.moves("BLLLBBB");
                    break;
                  }
                }
                else if (edge == 3) { //Colored edge on green side
                  switch(cube.cubies[5][3]) {
                    case 2:
                      cube.moves("RRRURFF");
                      break;
                    case 3:
                        cube.moves("R");
                        break;
                    case 4:
                        cube.moves("RRRUUURBB");
                        break;
                    case 5:
                        cube.moves("RRRUURLL");
                        break;

                        }
                      }
                else if (edge == 5) { //check color on blue side
                  switch(cube.cubies[3][5]) {
                    case 2:
                      cube.moves("LUUULLLFF");
                      break;
                    case 3:
                      cube.moves("LUULLLRR");
                      break;
                    case 4:
                      cube.moves("LULLLBB");
                      break;
                    case 5:
                      cube.moves("LLL");
                      break;
                    }
                  }
                  else if (edge == 7) { //check white side
                    switch (cube.cubies[7][0]) {
                      case 2:
                        cube.moves("BBURRRFR");
                        break;
                      case 3:
                        cube.moves("BRBBB");
                        break;
                      case 4:
                        cube.moves("BBURBBBRRR");
                        break;
                      case 5:
                        cube.moves("BBBLLLB");
                        break;
                      }
                    }
              break;
          case 5: //White edge on blue side

          if (edge == 1) {//Yellow side
            switch(cube.cubies[3][1]) {
              case 2:
                cube.moves("LFLLL");
                break;
              case 3:
                cube.moves("UUUFRRRFFF");
                break;
              case 4:
                cube.moves("LLLBL");
                break;
              case 5:
                cube.moves("UUUFFFLF");
                break;
            }
          }
          else if (edge == 3) { //Colored edge on orange side
            switch(cube.cubies[5][4]) {
              case 2:
                cube.moves("LLFFFLL");
                break;
              case 3:
                cube.moves("LUUUFRRRFFF");
                break;
              case 4:
                cube.moves("B");
                break;
              case 5:
                cube.moves("LUUUFFFLF");
                break;

            }
          }
          else if (edge == 5) { //check color on red side
            switch(cube.cubies[3][2]) {
            case 2:
              cube.moves("FFF");
              break;
            case 3:
              cube.moves("FUUUFFFRR");
              break;
            case 4:
              cube.moves("FUUFFFBB");
              break;
            case 5:
              cube.moves("FUFFFLL");
              break;
            }
          }
          else if (edge == 7) { //check white side
            switch (cube.cubies[3][0]) {
            case 2:
              cube.moves("LLLFFFL");
              break;
            case 3:
              cube.moves("LLUFRRRFFF");
              break;
            case 4:
              cube.moves("LBLLL");
              break;
            case 5:
              cube.moves("LLUFFFLF");
              break;
            }
          }

            break;

          case 0:
            if (edge == 1) {
              if (cube.cubies[7][2] != 2) {
                while (cube.cubies[1][2] == 0 || cube.cubies[7][1] == 0) {
                  cube.moves("U");
                }
                cube.moves("FF");
              }
            }
            else if (edge == 5) {
              if (cube.cubies[7][3] != 3) {
                while (cube.cubies[1][3] == 0 || cube.cubies[5][1] == 0) {
                  cube.moves("U");
                }
                cube.moves("RR");
              }
            }
            else if (edge == 7) {
              if (cube.cubies[7][4] != 4) {
                while (cube.cubies[1][3] == 0 || cube.cubies[1][1] == 0) {
                  cube.moves("U");
                }
                cube.moves("BB");
              }
            }
            else if (edge == 3) {
              if (cube.cubies[7][5] != 5) {
                while (cube.cubies[1][5] == 0 || cube.cubies[3][1] == 0) {
                  cube.moves("U");
                }
                cube.moves("LL");
              }
            }

            break;
        }
      }
    }
  }

}
