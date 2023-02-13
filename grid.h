#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include "point.h"
using namespace std;
class Grid {
public:
  int size;
  vector<vector<char>> grid;

  Grid(int size = 0);

  void drawLine(const Point& p1, const Point& p2);

  void display();
};

#endif
