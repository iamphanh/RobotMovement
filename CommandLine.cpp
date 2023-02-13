#include "CommandLine.h"

DimensionCmd::DimensionCmd(int size) : size(size) {}

void DimensionCmd::execute(Robot& robot) {
    
        robot.gid = Grid(size);
    
}

MoveToCmd::MoveToCmd(const Point& point) : point(point) {}

void MoveToCmd::execute(Robot& robot) {
    robot.moveTO(point);
}

LineToCmd::LineToCmd(const Point& point) : point(point) {}

void LineToCmd::execute(Robot& robot) {
    robot.lineTO(point);
}
