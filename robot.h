#ifndef ROBOT_H
#define ROBOT_H

#include "grid.h"
#include "point.h"

class Robot{
    public:
      Point pos;
      Grid gid;
      Robot(const Point& pos = Point(), const Grid& gid = Grid());
      
      bool checkPoint(const Point&p);

      void moveTO(const Point& p);

      void lineTO(const Point& p);  
};

#endif
