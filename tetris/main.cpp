#include"game.h"

using namespace std;


int main()
{
    Block1 b1;
    Block2 b2;
    Block3 b3;  
    Block4 b4;
    Block5 b5;
    
    Block6 b6;
    Block7 b7;
    Block arr[7] = {b1,b2,b3,b4,b5,b6,b7};
    Map map;
    int score = 0;
    playgame(arr,map,score);
    /*for(int i = 0; i < yEnd; i++){
        for(int j = 0; j < xEnd; j++)
            cout << map.canvas[i][j];
        cout << endl;
    }*/
    return 0;
    
}

 
  