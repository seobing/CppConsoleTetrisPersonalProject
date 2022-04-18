#ifndef __block_h__
#define __block_h__
#include"baseblock.h"

//배열로 block들 모양 선언
const int block1[4][4][4] = 
{
    {
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    }
};
const int block2[4][4][4] = 
{
    {
        {0,2,0,0},
        {0,2,0,0},
        {0,2,2,0},
        {0,0,0,0}
    },
    {
        {0,2,2,2},
        {0,2,0,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,0,2,0},
        {0,0,2,0},
        {0,0,0,0}
    },
    {
        {0,0,0,2},
        {0,2,2,2},
        {0,0,0,0},
        {0,0,0,0}
    }
};
const int block3[4][4][4] = 
{
    {
        {0,0,2,0},
        {0,0,2,0},
        {0,2,2,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {0,2,2,2},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,2,0,0},
        {0,2,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,2},
        {0,0,0,2},
        {0,0,0,0},
        {0,0,0,0}
    }
};
const int block4[4][4][4] = 
{
    {
        {2,2,2,2},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {0,2,0,0},
        {0,2,0,0},
        {0,2,0,0}
    },
    {
        {2,2,2,2},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {0,2,0,0},
        {0,2,0,0},
        {0,2,0,0}
    }
};
const int block5[4][4][4] = 
{
    {
        {0,0,2,0},
        {0,2,2,2},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {0,2,2,0},
        {0,2,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,2},
        {0,0,2,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,0,2,0},
        {0,2,2,0},
        {0,0,2,0},
        {0,0,0,0}
    }
};
const int block6[4][4][4] = 
{
    {
        {0,2,0,0},
        {0,2,2,0},
        {0,0,2,0},
        {0,0,0,0}
    },
    {
        {0,0,2,2},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,2,0,0},
        {0,2,2,0},
        {0,0,2,0},
        {0,0,0,0}
    },
    {
        {0,0,2,2},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    }
};
const int block7[4][4][4] = 
{
    {
        {0,0,2,0},
        {0,2,2,0},
        {0,2,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,0,2,2},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,0,2,0},
        {0,2,2,0},
        {0,2,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,0,2,2},
        {0,0,0,0},
        {0,0,0,0}
    }
};

class Block1 : public Block {
public:
    Block1(){
        x = xEnd/2-2;
        y = 1;
        rotationCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    blockShape[i][j][k] = block1[i][j][k];
                }
            }
        }
    }
};
class Block2 : public Block {
public:
    Block2(){
        x = xEnd/2-2;
        y = 1;
        rotationCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    blockShape[i][j][k] = block2[i][j][k];
                }
            }
        }
    }
};
class Block3 : public Block {
public:
    Block3(){
        x = xEnd/2-2;
        y = 1;
        rotationCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    blockShape[i][j][k] = block3[i][j][k];
                }
            }
        }
    }
};
class Block4 : public Block {
public:
    Block4(){
        x = xEnd/2-2;
        y = 1;
        rotationCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    blockShape[i][j][k] = block4[i][j][k];
                }
            }
        }
    }
};
class Block5 : public Block {
public:
    Block5(){
        x = xEnd/2-2;
        y = 1;
        rotationCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    blockShape[i][j][k] = block5[i][j][k];
                }
            }
        }
    }
};
class Block6 : public Block {
public:
    Block6(){
        x = xEnd/2-2;
        y = 1;
        rotationCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    blockShape[i][j][k] = block6[i][j][k];
                }
            }
        }
    }
};
class Block7 : public Block {
public:
    Block7(){
        x = xEnd/2-2;
        y = 1;
        rotationCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    blockShape[i][j][k] = block7[i][j][k];
                }
            }
        }
    }
};
#endif
