# RobotMovement
We have a robot and a square grid NxN. The robot moves and draw with the following commands:
DIMENSION N
Define the grid size
MOVE_TO x, y
Robot moves to (x, y) without drawing.
LINE_TO x, y
Move from current position to (x, y) with drawing on the grid.

In each square, the position of the robot is the center of the square. If the robot moves from square A to square B with the LINE_TO command, you draw a line from center of A to center of B and fill the squares that the line passes with + sign, including A and B. That is how the robot draws.
The index of grid row and column starts from 0. The default position of the robot is (0, 0). 

For example, with 5x5 grid and following commands
DIMENSION 5
MOVE_TO 1,1
LINE_TO 3,3
LINE_TO 2,3
Please write a console program to read the command from a text file and write the output to the console. With the following requirements:
Using pure C++, no external libraries.
Design in OOP so we can easily add more commands (such as CIRCLE_TO), or how to express the result (such as output to a bitmap image).
Handle input errors if possible.
