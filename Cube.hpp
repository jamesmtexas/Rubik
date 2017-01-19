#ifndef CUBE_H
#define CUBE_H

#include <iostream>

class Cube {

  public: int cubies[9][6];

  /* Set up Cube.
  If scramble set, call scramble.
  Else, set up a solved cube */
  public: Cube(bool);

  /* By default scramble sets
  cubies to a random state,
  using combination of move functions */
  private: void scramble();

  public:
  std::string printSequence(std::string);
  void moves(std::string);
  void output();
  void R(int);
  void L(int);
  void U(int);
  void D(int);
  void F(int);
  void B(int);
};
#endif
