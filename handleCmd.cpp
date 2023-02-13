#include "handleCmd.h"
#include "point.h"
#include <sstream>

CommandLine* handleCmd::createCommand(const std::string& commandStr) {
    std::istringstream iss(commandStr);
    std::string command;
    iss >> command;

    if (command == "DIMENSION") {
        int size;
        if (iss >> size) {
            if (size > 0){
                return new DimensionCmd(size);
            } else {
                cerr << "Please enter the correct grid size!!" << endl;
            }
            
        } else {
            cerr << "DIMENSION error syntax!" << endl << "The correct syntax is: DIMENSION n"
                << endl;
        }
    }
    else if (command == "MOVE_TO") {
        int x, y;
        char cmd;
        if (iss >> x >> cmd >> y) {
            Point point(x, y);
            return new MoveToCmd(point);
        }else {
            cerr << "MOVE_TO error syntax!" << endl << "The correct syntax is: MOVE_TO a,b"
                 << endl;
        }
    }
    else if (command == "LINE_TO") {
        int x, y;
        char cmd;
        if (iss >> x >> cmd >> y) {
            Point point(x, y);
            return new LineToCmd(point);
        }else {
            cerr << "LINE_TO error syntax!" << endl << "The correct syntax is: LINE_TO a,b"
                 << endl ;
        }
    }

    return nullptr;
}
