/*#include<iostream>
//#include<windows.h>
#include<vector>
#define xEnd 30
#define yEnd 40
using namespace std;

class Map{
    vector<vector<int>> line;
public:
    Map():line(yEnd,vector<int>(xEnd,0)){
        for(int i = 1; i <= yEnd; i++){
            for(int j = 1; j <= xEnd; j++){
                if(i == 1 || i == yEnd)
                    cout << "^";
                else if(j == 1 || j == xEnd)
                    cout << "|";
                else if(line[i][j] == 0)
                    cout << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Map map;
    return 0;
}*/