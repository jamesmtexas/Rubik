#include "Corners.hpp"
#include "Cube.hpp"


//Current version gets caught in a loop

void Corners::solveCorners(Cube &cube) {
  while (checkBottomLayer(cube)) {

    //get a white corner into the top layer

    if (cube.cubies[0][0] == 0 || cube.cubies[6][2] == 0 || cube.cubies[8][5] == 0) {
      while (cube.cubies[6][1] == 0 || cube.cubies[0][2] == 0 || cube.cubies[2][5] == 0 ) {
        cube.moves("U");
      }
      cube.moves("FUFFF");

    }
    if (cube.cubies[2][0] == 0 || cube.cubies[8][2] == 0 || cube.cubies[6][3] == 0) {
      while (cube.cubies[8][1] == 0 || cube.cubies[2][2] == 0 || cube.cubies[0][3] == 0 ) {
        cube.moves("U");
      }
      cube.moves("RURRR");

    }
    if (cube.cubies[6][0] == 0 || cube.cubies[8][4] == 0 || cube.cubies[6][5] == 0) {
      while (cube.cubies[0][1] == 0 || cube.cubies[2][4] == 0 || cube.cubies[0][5] == 0 ) {
        cube.moves("U");
      }
      cube.moves("LULLL");

    }
    if (cube.cubies[8][0] == 0 || cube.cubies[8][3] == 0 || cube.cubies[6][4] == 0) {
      while (cube.cubies[2][1] == 0 || cube.cubies[2][3] == 0 || cube.cubies[0][4] == 0 ) {
        cube.moves("U");
      }
      cube.moves("BUBBB");

    }
  }


  while (checkCorners(cube)) {

    //then perform the alg for the case: RUURRRUUURURRR, RURRR, FFFUUUF

    if (cube.cubies[8][1] == 0) {
      if (cube.cubies[2][2] == 2) { //red and blue
        cube.moves("UFUUFFFUUUFUFFF");
      }
      else if (cube.cubies[2][2] == 3) { //green and red
        cube.moves("RUURRRUUURURRR");
      }
      else if (cube.cubies[2][2] == 4) { //orange and green
        cube.moves("UUUBUUBBBUUUBUBBB");
      }
      else if (cube.cubies[2][2] == 5){ //orange and blue
        cube.moves("UULUUULLLUULULLL");
      }


    }

    else if (cube.cubies[0][3] == 0) {
        if (cube.cubies[2][2] == 2) { //red green
          cube.moves("RURRR");
        }
        else if (cube.cubies[2][2] == 3) { //green orange
          cube.moves("UUUBUBBB");
        }
        else if (cube.cubies[2][2] == 4) { //orange blue
          cube.moves("UULULLL");
        }
        else if (cube.cubies[2][2] == 5) { //red blue
          cube.moves("UFUFFF");
        }
    }

    else if (cube.cubies[2][2] == 0){
      if (cube.cubies[0][3] == 2) { //blue red
        cube.moves("ULLLUUUL");
      }
      else if (cube.cubies[0][3] == 3) { //red green
        cube.moves("FFFUUUF");
      }
      else if (cube.cubies[0][3] == 4) { //orange green
        cube.moves("URRRUUUR");
      }
      else if (cube.cubies[0][3] == 5) { //orange blue
        cube.moves("UUBBBUUUB");
      }

    }
    else {
      cube.moves("U");
    }

  }
}

int Corners::checkCorners(Cube &cube) {
  if (!cube.cubies[0][0] && !cube.cubies[2][0] && !cube.cubies[6][0] && !cube.cubies[8][0]) {

    return 0;
  }
  else {
    return 1;
  }
}

int Corners::checkBottomLayer(Cube &cube) {
  if (cube.cubies[0][0] && cube.cubies[2][0] && cube.cubies[6][0] && cube.cubies[8][0]
    && cube.cubies[6][2] && cube.cubies[8][2] && cube.cubies[6][3] && cube.cubies[8][3]
    && cube.cubies[6][4] && cube.cubies[8][4] && cube.cubies[6][5] && cube.cubies[8][5]) {

    return 0;
  }

  else if (!cube.cubies[0][0] && !cube.cubies[2][0] && !cube.cubies[6][0] && !cube.cubies[8][0]) {
    return 0;
  }

  else {
    return 1;
  }
}
