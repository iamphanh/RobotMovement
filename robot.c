#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Point {
    public:
       int x, y ;
    
       Point(int x = 0, int y = 0) : x(x) , y(y) {}
};

class Grid {
    public:
       int size;
       vector<vector<char>> grid;

       Grid(int size = 0) : size(size) {
        grid.resize(size);
        for(int i = 0 ; i < size ; i++){
            grid[i].resize(size,'.');
        }
       }
    
      // Bresenham's line algorithm
    void drawLine(const Point& h1, const Point& h2){
        int x1 = h1.x, y1 = h1.y;
        int x2 = h2.x, y2 = h2.y;
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

    void display(){
        for(int i = 0; i<size ; i++){
            for(int j = 0 ; j <size ; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
};

class Robot{
    public:
      Point pos;
      Grid gid;
      Robot(const Point& pos = Point(), const Grid& gid = Grid()) : pos(pos), gid(gid){}
      
      void moveTO(const Point& p){
        pos = p;
      }

      void lineTO(const Point& p){
        gid.drawLine(pos,p);
        pos = p;
      }  
};

int main(){
    Robot robot;
    string line;
    ifstream file("commands.txt");

    if(!file.is_open()){
        cerr << "Cannot open file !!!" << endl;
        return 1;
    }

    while (getline(file,line))
{
    istringstream iss(line);
    string command;
    iss >> command;
    if(command == "DIMENSION"){
        int size;
        if(iss >> size) {
            robot.gid = Grid(size);
        } else {
            cerr << "Error: Invalid size!" << endl;
        }
    } else if (command == "MOVE_TO"){
        int x, y;
        char cmd ;
        if(iss >> x >> cmd >> y) {
            robot.moveTO(Point(x,y));
        } else {
            cerr << "Error: Invalid coordinates!" << endl;
        }
    } else if (command == "LINE_TO"){
        int x,y;
        char cmd;
        if(iss >> x >> cmd >> y) {
            robot.lineTO(Point(x,y));
        } else {
            cerr << "Error: Invalid coordinates!" << endl;
        }
    } else {
        cerr << "Error: Unrecognized command!" << endl;
    }
}


    robot.gid.display();
    file.close();
    return 0;
    
}
