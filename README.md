# Rubik
<h2>Rubik's cube solver</h2>

~1500 sloc

Example usage:
cat scrambles.txt | ./Rubik

This is an automatic Rubik's cube solver in C++.
Input is received through stdin.
The output is the sequence of moves to solve the given scrambled cube.

<h3>Background</h3>
Rubik's cube can be solved fairly easily by a human using the "Beginner's method". This method consists of several independent steps.

Cross step:
Build a cross somewhere on the cube. By "cross" we mean solving all 4 edge pieces of a particular face, in their correct position with respect to the other faces.

Corners:
Next we solve each of the four corners on the same layer that we built the cross.

Edges: The center pieces are fixed, so the finish the second layer of the cube we simply need to solve the 4 edge pieces of the second layer.

OLL: OLL stands for Orient Last Layer. The beginner's method splits this into 2 steps: first we orient the edges, then the corners. This simplifies the step as we may check a smaller subsection of possible cases (9 cases rather than 57).

PLL: Finally, the Permutation of the Last Layer, or PLL. Again we divide this into two steps, first getting the corners into their correct position, then doing the same with the edges. This gives us 8 cases to check rather than the full 21.

<h3>Representation of the Rubik's cube</h3>
The Rubik's cube community uses a standard notation for moves on the cube. This notation consists of the face to rotate by 90 degrees clockwise: R L U D F B. Modifiers can be added to the move by adding a prime(\') to
the corresponding move. For example: F' means to rotate the front face 90 degrees counter clockwise.

To represent the state of the Rubik's cube, I use a 2D matrix [9][6]. There are 9 possible colors on each face of the cube, and there are 6 faces. This makes rotations somewhat difficult to represent.
I decided to hardcode each rotation function in the Cube class. I wasn't sure how else to do it, as when one face moves, the stickers on the adjacent pieces move as well. Despite this problem of somewhat complicated rotation function, this abstraction was very useful for developing the method for the solve.
