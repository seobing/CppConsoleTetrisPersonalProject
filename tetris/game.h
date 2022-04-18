#ifndef __GAME_H__
#define __GAME_H__
#include"keyboard.h"
#include<cstdlib>
#include<ctime>
#include<windows.h>

void save(Block* b, Map& m, int blockNum){
    for(int i = b[blockNum].getY(); i < b[blockNum].getY()+4; i++){
        if(i >= yEnd - 1){
            //cout << "hi\n";
            continue;
        }
        for(int j = b[blockNum].getX(); j < b[blockNum].getX()+4; j++){
            //cout << i;
            m.canvas2[i][j] += b[blockNum].getShape(b[blockNum].getRotationCount(),i-b[blockNum].getY(),j-b[blockNum].getX());
        }
    }    
//}
    //copy(m.canvas2.begin(), m.canvas2.end(), m.canvas.begin());
}

void preview(Block& b, Map& m){
    /*int sum = 0;
    int ylen = 0;
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sum += b.getShape(b.getRotationCount(),i,j);
        }
        if(sum == 0){
            ylen = i-1;
            break;
        }
        ylen = i;
        sum = 0;
    }*/
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
                            if(b.getShape(b.getRotationCount(),yy-b.getY(),xx-b.getX()) == 2)
                                m.canvas[yy][xx] += b.getShape(b.getRotationCount(),yy-b.getY(),xx-b.getX())+4;
                        }
                    }
                    return;
                }
            }
        }
        b.down();
    }
}

void playgame(Block* b, Map& m, int& score){
    int tempy;
    int count = 0;
    int blockNum;
    srand(time(NULL));
    blockNum = rand()%7;
    time_t t, t2;
    t = time(NULL);
    for(;;){
        for(int i = 1; i < 4; i++){
            for(int j = 0; j < 4; j++){
                count += b[blockNum].getShape(b[blockNum].getRotationCount(),i,j);
            }
            if(count == 0){
                tempy = i+b[blockNum].getY()-1;
                break;
            }
            tempy = i+b[blockNum].getY();
            count = 0;
        }
        t2 = time(NULL);
        if(t+2 == t2){
            b[blockNum].down();
            tempy++;
            t = t2;
        }
        system("cls");
        m.clear();
        if(tempy >= yEnd-2)
            save(b,m,blockNum);
        copy(m.canvas2.begin(), m.canvas2.end(), m.canvas.begin());   
        //cout << blockNum << endl;
        //m.clear();
        //save(b,m,tempy,blockNum);
        keyboard(b[blockNum],m);
        //cout << tempy << endl;
        //블럭이 가장 아랫줄까지 내려온 경우
        if(tempy >= yEnd-2){
            blockNum = rand()%7;
            //cout << "hello\n";
            b[blockNum].setX(xEnd/2-2);
            b[blockNum].setY(1);
            continue;    
        }
        for(int i = b[blockNum].getY(); i < b[blockNum].getY()+4; i++){
            
            if(i >= yEnd - 1){
                //cout << "hi\n";
                continue;
            }
            for(int j = b[blockNum].getX(); j < b[blockNum].getX()+4; j++){
                //cout << i;
                m.canvas[i][j] += b[blockNum].getShape(b[blockNum].getRotationCount(),i-b[blockNum].getY(),j-b[blockNum].getX());
            }
            //cout << endl;
        }
        //블럭이 다른 블럭과 맞닿은 경우
        for(int j = b[blockNum].getX(); j < b[blockNum].getX()+4; j++){
            for(int i = b[blockNum].getY(); i < b[blockNum].getY()+4; i++){
                if(i >= yEnd - 1){
                    continue;
                }
                if(m.canvas[i+1][j] + b[blockNum].getShape(b[blockNum].getRotationCount(),i-b[blockNum].getY(),j-b[blockNum].getX()) == 3 || 
                m.canvas2[i+1][j] + b[blockNum].getShape(b[blockNum].getRotationCount(),i-b[blockNum].getY(),j-b[blockNum].getX()) == 4 ){
                    save(b,m,blockNum);
                    blockNum = rand()%7;
                    //cout << "hello\n";
                    b[blockNum].setX(xEnd/2-2);
                    b[blockNum].setY(1);
                    for(int y = b[blockNum].getY(); y < b[blockNum].getY() + 4; y++){
                        for(int x = b[blockNum].getX(); x < b[blockNum].getX() +4; x++){
                            if(m.canvas[y][x] == 4){
                                cout << "GAME OVER!!!!!!!\n";
                                cout << "YOUR SCORE IS " << score << endl;
                                return;
                            }
                        }
                    }
                    break;         
                }
            }
        }
        int sum = 0;
        int tempi;
        int line = 0;
        for(int i = 1; i < yEnd-1; i++){
            for(int j = 1; j < xEnd-1; j++){
                sum += m.canvas2[i][j];
            }
            if(2*(xEnd-2) == sum){ 
                tempi = i;
                line++;
            }
            sum = 0;
        }
        for(int i = 0 ; i < line; i++)
            score += line*1000;
        if(line != 0){
            for(int k = 0; k < line; k++){
                for(int i = tempi; i >= 1; i--){
                    for(int j = 1; j < xEnd-1; j++){
                        m.canvas2[i][j] = m.canvas2[i-1][j];
                    }
                }
            }
            for(int i = 1; i < line; i++){
                for(int j = 1; j < xEnd -1; j++){
                    m.canvas2[i][j] = 0;
                }
            }
        }
        
        Block tempblock = b[blockNum];
        preview(tempblock,m);
        m.print();
        cout << endl << "SCORE: " << score << endl;
    }
}



#endif
