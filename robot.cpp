#include "robot.h"

Robot::Robot(const Point& pos, const Grid& gid) : pos(pos), gid(gid){}

void Robot::moveTO(const Point& p){
    if (checkPoint(p) == 1)
    {
        cerr << "Erorr: Point (" << p.x << "," << p.y << ") is out of grid!!!" << endl;
    }else {
        pos = p;
    }
}

void Robot::lineTO(const Point& p){
    if (checkPoint(p)== 1)
    {
        cerr << "Erorr: Point (" << p.x << "," << p.y << ") is out of grid!!!" << endl;
    }else {
      gid.drawLine(pos,p);
      pos = p;
    }
}

bool Robot::checkPoint(const Point& p){
    if(p.x < 0 || p.x > gid.size || p.y < 0 || p.y > gid.size ){
       return 1;
    } else return 0;
}
