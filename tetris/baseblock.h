#ifndef __BASEBLOCK_H__
#define __BASEBLOCK_H__
#include "map.h"
class Block{
protected:
    int blockShape[4][4][4];
    int x;
    int y;
    int rotationCount;
public:
    int getShape(int rotationCount, int y, int x){
        return blockShape[rotationCount][y][x];
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getRotationCount(){
        return rotationCount;
    }
    void down(){
        y++;
    }
    void up(){
        y--;
    }
    void left(){
        x--;
    }
    void right(){
        x++;
    }
    //void rotate(){
    //    rotationCount = (rotationCount+1)%4;
    //}
    void setX(int x){
        this-> x = x;
    }
    void setY(int y){
        this-> y = y;
    }
    void setRotationCount(int r){
        this-> rotationCount = r;
    }
    void setShape(int r, int y, int x, int value){
        this -> blockShape[r][y][x] = value;
    }

};
#endif 