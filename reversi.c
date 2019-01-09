#include <stdio.h>
#include <stdlib.h>

#define Row 8
#define Column 8
#define Black 1
#define White 2
#define MaxEval  1000
#define MinEval -1000


void defineTable(int table[Row][Column],char *argv[]);
void printTable(int table[Row][Column]);
void printtable1D(int table[]);
void flip(int table[],int square,int jump,int player);
void doflip(int table[], int square , int player);
//////////////////////// Valid Moves ///////////////////////////////////
int isPair(int square, int table[], int jump, int player);
void validSquares(int table[], int arrayOfValids[], int player);

/////////////////////// MiniMax ////////////////////////////////////////
// int minimax(position , depth , isMaxPly);
// int evalPosition(position);
// int canMove(position);


int main(int argc,char *argv[])
{
    int table[Row][Column]={
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,1 ,2 ,0 ,0 ,0},

        {0 ,0 ,0 ,2 ,1 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
    };

    int table1D[] ={
        0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,

        0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,

        0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,

        0 ,0 ,0 ,1 ,2 ,0 ,0 ,0,

        0 ,0 ,0 ,2 ,1 ,0 ,0 ,0,

        0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,

        0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,

        0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
    };

    int arrayOfValids[Row*Column];



    // int const Player= argv[9][0]-48;
    // defineTable(table,argv);
    validSquares(table1D,arrayOfValids,1);
    
    int i =0;
    while(arrayOfValids[i]!=-1){
        printf("%d\n",arrayOfValids[i]);
        i++;
    }
 
    printtable1D(table1D);



    
    // int counter;
    // printf("Program Name Is: %s",argv[0]);
    // if(argc==1)
    //     printf("\nNo Extra Command Line Argument passed Other Than program Name");
    // if(argc>=2)
    // {
    //     printf("\nNumber Of Arguments passed: %d\n",argc);
    //     printf("\n----Following Are The Command Line Arguments Passed----");
    //     for(counter=0;counter<argc;counter++)
    //         printf("\nargv[%d]:%s",counter,argv[counter]);
    // }
    return 0;
}

void defineTable(int table[Row][Column],char *argv[])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            table[i][j]= argv[i+1][j] - 48 ;
        }
    }

}

// void printTable(int table[Row][Column]){         //  delete it !
//     puts("");
//     for(int i=0;i<Row;i++){
//         for(int j=0;j<Column;j++){
//             printf("%d ",table[i][j]);
//         }
//         puts("");
//     }

// }

void printtable1D(int table[]){
    puts("");
    for(int i=0;i<Row;i++){
        for(int j=0;j<Column;j++){
            printf("%d ",table[i*8+j]);
        }
        puts("");
    }

}

void flip(int table[],int square,int jump,int player){
    if(isPair(square,table,jump,player)){
        table[square]=player;
        square += jump;
        while(table[square] == 3-player){
            table[square] = player;
            square += jump;
        }
    }
    
}

void doflip(int table[], int square , int player){
    flip(table,square,-9,player);
    flip(table,square,-8,player);
    flip(table,square,-7,player);
    flip(table,square,-1,player);
    flip(table,square,+1,player);
    flip(table,square,+7,player);
    flip(table,square,+8,player);
    flip(table,square,+9,player);
}

///////////////////////////////////////////////////////////////////////////
/////////////////////// Valid Moves Function //////////////////////////////

int isPair(int square, int table[], int jump, int player){
    int temp = square + jump;
    do{
        square += jump;
    }while(table[square] == 3-player);
    
    if(temp!=square && table[square]==player) return 1;
    else return 0;
}

void validSquares(int table[],int arrayOfValids[],int player){
    int counter = 0;
    for(int i =0;i<Row*Column;i++){
        if(isPair(i,table,-9,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }else if(isPair(i,table,-8,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }else if(isPair(i,table,-7,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }else if(isPair(i,table,-1,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }else if(isPair(i,table,+1,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }else if(isPair(i,table,+7,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }else if(isPair(i,table,+8,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }else if(isPair(i,table,+9,player)==1){
            arrayOfValids[counter]=i;
            counter ++;
        }

        arrayOfValids[counter]=-1;

        // switch(1){
        //     case isPair(square,table,-8,player) :

        // }
    }
}

///////////////////////////////////////////////////////////////////////////
/////////////////////////////// MiniMax ///////////////////////////////////

// int minimax(position , depth , isMaxPly){
//     if(depth == 0 || !canMove() ){
//         return evalPosition(position);
//     }

//     if(isMaxPly){

//     }
// }

// int evalPosition(position){

// }

// int canMove(position){

// }
