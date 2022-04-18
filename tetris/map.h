#ifndef __MAP_H__
#define __MAP_H__
#include<iostream>
//#include<windows.h>
#include<vector>
#define xEnd 20
#define yEnd 20
using namespace std;

class Map{
public:
    vector<vector<int>> canvas;
    vector<vector<int>> canvas2;
public:
    Map():canvas(yEnd,vector<int>(xEnd,0)),canvas2(yEnd,vector<int>(xEnd,0)){
        for(int i = 0; i < yEnd; i++){
            for(int j = 0; j < xEnd; j++){
                if(j == 0 || j == xEnd-1){
                    canvas2[i][j] = 1;
                }
                else if(i == yEnd-1){
                    canvas2[i][j] = 1;
                }
            }
        }
    }
    //vector<vector<int>> getLine(){
    //    return this -> line;
    //}
    void print(){
        /*cout << "!! ***  ***  ***  ***  *   ** !!\n";
        cout << "!!  *   ***   *   **   *  ** *!!\n";
        cout << "!!  *   ***   *   * *  *   ** !!\n";
        cout << "|| = = = = = = = = = = = = = =||\n";*/
        for(int i = 0; i < yEnd; i++){
            for(int j = 0; j < xEnd; j++){
                if(canvas[i][j] == 4) canvas[i][j] = 0;
                if(j == 0 || j == xEnd-1){
                    canvas[i][j] = 1;
                    cout << "||";
                }
                else if(i == yEnd-1){
                    canvas[i][j] = 1;
                    cout << "=";
                }
                else if(canvas[i][j] == 2){
                    cout << "M";
                }
                else if(canvas[i][j] == 0)
                    cout << " ";
                else if(canvas[i][j] == 6)
                    cout << "*";
                else if(canvas[i][j] == 8)
                    cout <<  "M";

            }
        cout << endl;
        }      
    }
    void clear(){
        for(int i = 0; i <yEnd-1; i++){
            for(int j = 1;j < xEnd-1; j++){
                canvas[i][j] = 0;
            }
        }
    }
};


#endif 