#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__
#include"block.h"
#include <conio.h>

// 상하좌우 상수값 설정
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

void keyboard(Block& b,Map& m){
    int rot;
    char c;
    int count = 0;
    int tempx;
    int tempy;
    if (_kbhit()) {        //키보드 입력 확인 (true / false)
        c = _getch();      // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
        //if (c == -32) {    // -32로 입력되면
            //c = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
            switch (c) {
            case LEFT:
                for(int j = 0; j < 2; j++){
                    for(int i = 0; i < 4; i++){
                        count += b.getShape(b.getRotationCount(),i,j);
                    }
                    if(count == 0){
                        tempx = j+b.getX()+1;
                        break;
                    }
                    tempx = j+b.getX()-1;
                    count = 0;
                }
                if(m.canvas[b.getY()][tempx-1] != 1){
                    for(int i = b.getY(); i < b.getY()+4; i++){
                        for(int j = b.getX(); j < b.getX()+4; j++){
                            if(m.canvas2[i][j-1] + b.getShape(b.getRotationCount(),i-b.getY(),j-b.getX()) == 4){
                                return;
                            }
                        }
                    }
                    b.left();
                    b.getX();
                }
                break;
            case RIGHT:
                for(int j = 2; j < 4; j++){
                    for(int i = 0; i < 4; i++){
                        count += b.getShape(b.getRotationCount(),i,j);
                    }
                    if(count == 0){
                        tempx = j+b.getX()-1;
                        break;
                    }
                    tempx = j+b.getX();
                    count = 0;
                }
                if(m.canvas[b.getY()][tempx+1] != 1 ){
                    for(int i = b.getY(); i < b.getY()+4; i++){
                        for(int j = b.getX(); j < b.getX()+4; j++){
                            if(m.canvas2[i][j+1] + b.getShape(b.getRotationCount(),i-b.getY(),j-b.getX()) == 4){
                                return;
                            }
                        }
                    }
                    b.right();
                    b.getX();
                }
                break;
            case UP:
                rot = (b.getRotationCount() +1)%4;
                b.setRotationCount((rot));
                for(int i = b.getY();i < b.getY()+4; i++ ){
                    for(int j = b.getX(); j < b.getX()+4; j++){
                        if(m.canvas[i][j]+b.getShape(b.getRotationCount(),i-b.getY(),j-b.getX()) == 4){
                            b.setRotationCount((rot+3)%4);
                            return;
                        }
                    }
                }
                for(int j = 2; j < 4; j++){
                    for(int i = 0; i < 4; i++){
                        count += b.getShape(b.getRotationCount(),i,j);
                    }
                    if(count == 0){
                        tempx = j + b.getX()-1;
                        break;
                    }
                    tempx = j+b.getX();
                    count = 0;
                }
                if(tempx >= xEnd - 1){//블럭을 맨오른쪽으로 붙이고 로테이션 돌렸을 때 판 빆으로 벗어나는 경우
                    for(int i = 0; i <= tempx -(xEnd -1); i++){
                        b.left();
                        b.getX();
                    }
                    break;
                }
                for(int j = 0; j < 2; j++){
                    for(int i = 0; i < 4; i++){
                        count += b.getShape(b.getRotationCount(),i,j);
                    }
                    if(count == 0){

                        tempx = j+b.getX()+1;
                        break;
                    }
                    tempx = j+b.getX()-1;
                    count = 0;
                }
                if(tempx == 0){
                    for(int i = 0; i <= 0 - tempx; i++){
                        b.right();
                        b.getX();
                    }
                    break;
                }
                for(int i = 1; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        count += b.getShape(b.getRotationCount(),i,j);
                    }
                    if(count == 0){
                        tempy = i+b.getY()-1;
                        break;
                    }
                    tempy = i+b.getY();
                    count = 0;
                    }
                cout << tempy << endl;
                if(tempy >= yEnd - 1){
                    for(int i = 0; i <= tempy -(yEnd -1); i++){
                        b.up();
                        b.getY();
                    }
                    break;
                }
                break;
            case DOWN:
                b.down();
                b.getY();
                break;
            case SPACE: //블럭 위로 쌓이는건 추후에 고려
                for(int i = 1; i < yEnd-1; i++){
                    for(int j = b.getY(); j < b.getY()+4; j++){
                        for(int k = b.getX(); k < b.getX()+4; k++){
                            if(j >= yEnd -1){
                                continue;
                            }
                            if(m.canvas2[j+1][k] + b.getShape(b.getRotationCount(),j-b.getY(),k-b.getX()) == 3 || m.canvas2[j+1][k] + b.getShape(b.getRotationCount(),j-b.getY(),k-b.getX()) == 4){
                                b.setY(b.getY());
                                for(int yy = b.getY(); yy < b.getY()+4; yy++){
                                    if(yy >= yEnd-1){
                                        continue;
                                    }
                                    for(int xx = b.getX(); xx < b.getX()+4; xx++){
                                        //if(b.getShape(b.getRotationCount(),yy-b.getY(),xx-b.getX()) == 2)
                                        m.canvas[yy][xx] = b.getShape(b.getRotationCount(),yy-b.getY(),xx-b.getX());
                                    }
                                }
                                return;
                            }
                        }
                    }
                    b.down();
                }
                break;
            }
        //}
    }
}

#endif