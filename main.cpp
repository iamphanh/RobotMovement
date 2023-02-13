#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include "CommandLine.cpp"
#include "grid.cpp"
#include "robot.cpp"
#include "handleCmd.cpp"
using namespace std;

int main() {
    Robot robot;
    int count = 1 ;
    ifstream file("command.txt");
    if (!file.is_open()) {
        cerr << "Cannot open file !!!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        CommandLine* command = handleCmd::createCommand(line);
        if (command != nullptr) {
            command->execute(robot);
            delete command;
        }
        else {
            cerr << "Error: Unrecognized or invalid command on line " << count << endl;
        }
        count++;
    }
    robot.gid.display();
    file.close();
    return 0;
}

