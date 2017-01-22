#include "Cube.hpp"
#include <iostream>

Cube::Cube(bool scrambled) {

  for (int sticker=0; sticker<9; ++sticker) {
    for (int side=0; side<6; ++side) {
      if (side==0) {
        Cube::cubies[sticker][side] = 0; //White
      }
      else if(side==1) {
        Cube::cubies[sticker][side] = 1; //Yellow
      }
      else if(side==2) {
        Cube::cubies[sticker][side] = 2; //Red
      }
      else if(side==3) {
        Cube::cubies[sticker][side] = 3; //Green
      }
      else if(side==4) {
        Cube::cubies[sticker][side] = 4; //Orange
      }
      else if(side==5) {
        Cube::cubies[sticker][side] = 5; //Blue
      }
    }
  }

  if (scrambled) {
    Cube::scramble();
  }
}
void Cube::moves(std::string sequence) {
  std::string outputSequence = "";
  int sequenceLength = sequence.length();
  for (int i=0; i<sequenceLength; ++i) {
    switch (sequence[i]) {
      case 'U':
        U(1);
        break;
      case 'D':
        D(1);
        break;
      case 'R':
        R(1);
        break;
      case 'L':
        L(1);
        break;
      case 'F':
        F(1);
        break;
      case 'B':
        B(1);
        break;
    }
  }

  std::cout << printSequence(sequence) << std::endl;
  //output();
}

std::string Cube::printSequence(std::string sequence) {
  std::string newSequence;
  for (int i=0; i < sequence.length(); ++i) {
    if (sequence.length() > (i+2)) {
      if ((sequence[i] == sequence[i+1]) && (sequence[i] == sequence[i+2])){ // RRR -> R'
        newSequence += sequence[i];
        newSequence += "\'";
        i+=2;
      }
      else if (sequence[i] == sequence[i+1]) {
        newSequence += sequence[i];
        newSequence += "2";
        i += 1;
      }
      else {
        newSequence += sequence[i];
      }
    }
    else if (sequence.length() > (i+1)) {
      if (sequence[i] == sequence[i+1]) {
        newSequence += sequence[i];
        newSequence += "2";
        i += 1;
      }
      else {
        newSequence += sequence[i];
      }
    }
    else {
      newSequence += sequence[i];
    }

    newSequence += " ";

  }

  return newSequence;
}

void Cube::output() {
  std::cout << "White:" << std::endl;
  for (int i=0; i<9; i+=0) {
    for (int j=0; j<3; ++j) {
      std::cout << cubies[i][0];
      ++i;
    }
    std::cout << std::endl;
  }
  std::cout << "Yellow:" << std::endl;
  for (int i=0; i<9; i+=0) {
    for (int j=0; j<3; ++j) {
      std::cout << cubies[i][1];
      ++i;
    }
    std::cout << std::endl;
  }
  std::cout << "Red:" << std::endl;
  for (int i=0; i<9; i+=0) {
    for (int j=0; j<3; ++j) {
      std::cout << cubies[i][2];
      ++i;
    }
    std::cout << std::endl;
  }
  std::cout << "Green:" << std::endl;
  for (int i=0; i<9; i+=0) {
    for (int j=0; j<3; ++j) {
      std::cout << cubies[i][3];
      ++i;
    }
    std::cout << std::endl;
  }
  std::cout << "Orange:" << std::endl;
  for (int i=0; i<9; i+=0) {
    for (int j=0; j<3; ++j) {
      std::cout << cubies[i][4];
      ++i;
    }
    std::cout << std::endl;
  }
  std::cout << "Blue:" << std::endl;
  for (int i=0; i<9; i+=0) {
    for (int j=0; j<3; ++j) {
      std::cout << cubies[i][5];
      ++i;
    }
    std::cout << std::endl;
  }

}

void Cube::scramble() {
  //generate random string and call moves()

}

void Cube::R(int n) {

  int newCubies[9][6];
  for (int i=0;i<9;++i) {
    for (int j=0;j<6;++j) {
      newCubies[i][j] = Cube::cubies[i][j];
    }
  }

  if (n>=0) {
    for (int x=0; x<n; ++x) {

      //Orange->White
      newCubies[2][0] = Cube::cubies[6][4];
      newCubies[5][0] = Cube::cubies[3][4];
      newCubies[8][0] = Cube::cubies[0][4];

      //White->Red
      newCubies[2][2] = Cube::cubies[2][0];
      newCubies[5][2] = Cube::cubies[5][0];
      newCubies[8][2] = Cube::cubies[8][0];

      //Red->Yellow
      newCubies[2][1] = Cube::cubies[2][2];
      newCubies[5][1] = Cube::cubies[5][2];
      newCubies[8][1] = Cube::cubies[8][2];

      //Yellow->Orange
      newCubies[6][4] = Cube::cubies[2][1];
      newCubies[3][4] = Cube::cubies[5][1];
      newCubies[0][4] = Cube::cubies[8][1];

      //Rotate Green
      newCubies[0][3] = Cube::cubies[6][3];
      newCubies[1][3] = Cube::cubies[3][3];
      newCubies[2][3] = Cube::cubies[0][3];
      newCubies[3][3] = Cube::cubies[7][3];
      newCubies[5][3] = Cube::cubies[1][3];
      newCubies[6][3] = Cube::cubies[8][3];
      newCubies[7][3] = Cube::cubies[5][3];
      newCubies[8][3] = Cube::cubies[2][3];

      for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
          Cube::cubies[i][j] = newCubies[i][j];
        }
      }

    }
  }



}

void Cube::L(int n) {

  int newCubies[9][6];
  for (int i=0;i<9;++i) {
    for (int j=0;j<6;++j) {
      newCubies[i][j] = Cube::cubies[i][j];
    }
  }

  if (n>=0) {

    for (int x=0; x<n; ++x) {

      //White->Orange
      newCubies[2][4] = Cube::cubies[6][0];
      newCubies[5][4] = Cube::cubies[3][0];
      newCubies[8][4] = Cube::cubies[0][0];

      //Orange->Yellow
      newCubies[6][1] = Cube::cubies[2][4];
      newCubies[3][1] = Cube::cubies[5][4];
      newCubies[0][1] = Cube::cubies[8][4];

      //Yellow->Red
      newCubies[0][2] = Cube::cubies[0][1];
      newCubies[3][2] = Cube::cubies[3][1];
      newCubies[6][2] = Cube::cubies[6][1];

      //Red->White
      newCubies[0][0] = Cube::cubies[0][2];
      newCubies[3][0] = Cube::cubies[3][2];
      newCubies[6][0] = Cube::cubies[6][2];

      //Rotate Blue
      newCubies[0][5] = Cube::cubies[6][5];
      newCubies[1][5] = Cube::cubies[3][5];
      newCubies[2][5] = Cube::cubies[0][5];
      newCubies[3][5] = Cube::cubies[7][5];
      newCubies[5][5] = Cube::cubies[1][5];
      newCubies[6][5] = Cube::cubies[8][5];
      newCubies[7][5] = Cube::cubies[5][5];
      newCubies[8][5] = Cube::cubies[2][5];

      for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
          Cube::cubies[i][j] = newCubies[i][j];
        }
      }

    }
  }


}

void Cube::U(int n) {

  int newCubies[9][6];
  for (int i=0;i<9;++i) {
    for (int j=0;j<6;++j) {
      newCubies[i][j] = Cube::cubies[i][j];
    }
  }

  if (n>=0) {

    for (int x=0; x<n; ++x) {

      //Orange->Green
      newCubies[0][3] = Cube::cubies[0][4];
      newCubies[1][3] = Cube::cubies[1][4];
      newCubies[2][3] = Cube::cubies[2][4];

      //Green->Red
      newCubies[0][2] = Cube::cubies[0][3];
      newCubies[1][2] = Cube::cubies[1][3];
      newCubies[2][2] = Cube::cubies[2][3];

      //Red->Blue
      newCubies[0][5] = Cube::cubies[0][2];
      newCubies[1][5] = Cube::cubies[1][2];
      newCubies[2][5] = Cube::cubies[2][2];

      //Blue->Orange
      newCubies[0][4] = Cube::cubies[0][5];
      newCubies[1][4] = Cube::cubies[1][5];
      newCubies[2][4] = Cube::cubies[2][5];

      //Rotate Yellow
      newCubies[0][1] = Cube::cubies[6][1];
      newCubies[1][1] = Cube::cubies[3][1];
      newCubies[2][1] = Cube::cubies[0][1];
      newCubies[3][1] = Cube::cubies[7][1];
      newCubies[5][1] = Cube::cubies[1][1];
      newCubies[6][1] = Cube::cubies[8][1];
      newCubies[7][1] = Cube::cubies[5][1];
      newCubies[8][1] = Cube::cubies[2][1];

      for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
          Cube::cubies[i][j] = newCubies[i][j];
        }
      }

    }
  }

}

void Cube::D(int n) {

  int newCubies[9][6];
  for (int i=0;i<9;++i) {
    for (int j=0;j<6;++j) {
      newCubies[i][j] = Cube::cubies[i][j];
    }
  }

  if (n>=0) {

    for (int x=0; x<n; ++x) {

      //Orange->Blue
      newCubies[6][5] = Cube::cubies[6][4];
      newCubies[7][5] = Cube::cubies[7][4];
      newCubies[8][5] = Cube::cubies[8][4];

      //Blue->Red
      newCubies[6][2] = Cube::cubies[6][5];
      newCubies[7][2] = Cube::cubies[7][5];
      newCubies[8][2] = Cube::cubies[8][5];

      //Red->Green
      newCubies[6][3] = Cube::cubies[6][2];
      newCubies[7][3] = Cube::cubies[7][2];
      newCubies[8][3] = Cube::cubies[8][2];

      //Green->Orange
      newCubies[6][4] = Cube::cubies[6][3];
      newCubies[7][4] = Cube::cubies[7][3];
      newCubies[8][4] = Cube::cubies[8][3];

      //Rotate White
      newCubies[0][0] = Cube::cubies[6][0];
      newCubies[1][0] = Cube::cubies[3][0];
      newCubies[2][0] = Cube::cubies[0][0];
      newCubies[3][0] = Cube::cubies[7][0];
      newCubies[5][0] = Cube::cubies[1][0];
      newCubies[6][0] = Cube::cubies[8][0];
      newCubies[7][0] = Cube::cubies[5][0];
      newCubies[8][0] = Cube::cubies[2][0];

      for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
          Cube::cubies[i][j] = newCubies[i][j];
        }
      }

    }
  }


}

void Cube::F(int n) {

  int newCubies[9][6];
  for (int i=0;i<9;++i) {
    for (int j=0;j<6;++j) {
      newCubies[i][j] = Cube::cubies[i][j];
    }
  }

  if (n>=0) {

    for (int x=0; x<n; ++x) {

      //Blue->Yellow
      newCubies[8][1] = Cube::cubies[2][5];
      newCubies[7][1] = Cube::cubies[5][5];
      newCubies[6][1] = Cube::cubies[8][5];

      //Yellow->Green
      newCubies[0][3] = Cube::cubies[6][1];
      newCubies[3][3] = Cube::cubies[7][1];
      newCubies[6][3] = Cube::cubies[8][1];

      //Green->White
      newCubies[2][0] = Cube::cubies[0][3];
      newCubies[1][0] = Cube::cubies[3][3];
      newCubies[0][0] = Cube::cubies[6][3];

      //White->Blue
      newCubies[2][5] = Cube::cubies[0][0];
      newCubies[5][5] = Cube::cubies[1][0];
      newCubies[8][5] = Cube::cubies[2][0];

      //Rotate Red
      newCubies[0][2] = Cube::cubies[6][2];
      newCubies[1][2] = Cube::cubies[3][2];
      newCubies[2][2] = Cube::cubies[0][2];
      newCubies[3][2] = Cube::cubies[7][2];
      newCubies[5][2] = Cube::cubies[1][2];
      newCubies[6][2] = Cube::cubies[8][2];
      newCubies[7][2] = Cube::cubies[5][2];
      newCubies[8][2] = Cube::cubies[2][2];

      for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
          Cube::cubies[i][j] = newCubies[i][j];
        }
      }

    }
  }


}

void Cube::B(int n) {

  int newCubies[9][6];
  for (int i=0;i<9;++i) {
    for (int j=0;j<6;++j) {
      newCubies[i][j] = Cube::cubies[i][j];
    }
  }

  if (n>=0) {

    for (int x=0; x<n; ++x) {

      //Yellow->Blue
      newCubies[6][5] = Cube::cubies[0][1];
      newCubies[3][5] = Cube::cubies[1][1];
      newCubies[0][5] = Cube::cubies[2][1];

      //Blue->White
      newCubies[6][0] = Cube::cubies[0][5];
      newCubies[7][0] = Cube::cubies[3][5];
      newCubies[8][0] = Cube::cubies[6][5];

      //White->Green
      newCubies[8][3] = Cube::cubies[6][0];
      newCubies[5][3] = Cube::cubies[7][0];
      newCubies[2][3] = Cube::cubies[8][0];

      //Green->Yellow
      newCubies[0][1] = Cube::cubies[2][3];
      newCubies[1][1] = Cube::cubies[5][3];
      newCubies[2][1] = Cube::cubies[8][3];

      //Rotate Orange
      newCubies[0][4] = Cube::cubies[6][4];
      newCubies[1][4] = Cube::cubies[3][4];
      newCubies[2][4] = Cube::cubies[0][4];
      newCubies[3][4] = Cube::cubies[7][4];
      newCubies[5][4] = Cube::cubies[1][4];
      newCubies[6][4] = Cube::cubies[8][4];
      newCubies[7][4] = Cube::cubies[5][4];
      newCubies[8][4] = Cube::cubies[2][4];

      for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
          Cube::cubies[i][j] = newCubies[i][j];
        }
      }

    }
  }


}
