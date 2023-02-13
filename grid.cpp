#include "grid.h"

Grid::Grid(int size) : size(size) {
  grid.resize(size);
  for (int i = 0; i < size; i++) {
    grid[i].resize(size, '.');
  }
}

      // Bresenham's line algorithm
void Grid::drawLine(const Point& p1, const Point& p2) {
  int x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
  int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
  int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2;

  while (true) {
    grid[x1][y1] = '+';
    if (x1 == x2 && y1 == y2) break;
    int e2 = err;
    if (e2 > -dx) { err -= dy; x1 += sx; }
    if (e2 <  dy) { err += dx; y1 += sy; }
  }
}

void Grid::display() {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}
