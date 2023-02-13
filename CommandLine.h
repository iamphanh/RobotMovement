#pragma once

#include "grid.h"
#include "point.h"
#include "robot.h"
class CommandLine {
public:
    virtual void execute(Robot& robot) = 0;
};

class DimensionCmd : public CommandLine {
public:
    DimensionCmd(int size);
    void execute(Robot& robot) override;

private:
    int size;
};

class MoveToCmd : public CommandLine {
public:
    MoveToCmd(const Point& point);
    void execute(Robot& robot) override;

private:
    Point point;
};

class LineToCmd : public CommandLine {
public:
    LineToCmd(const Point& point);
    void execute(Robot& robot) override;

private:
    Point point;
};
