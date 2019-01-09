#include <stdio.h>
#include <stdlib.h>

#define row 8
#define column 8
#define black 1
#define white 2

void defineTable(int table[row][column],char *argv[]);
void printTable(int table[row][column]);

//////////////////////// Valid Moves ///////////////////////////////////
int isPair(int square, int table[], int jump, int player);

void validSquares(int table[], int arrayOfValids[], int player);

/////////////////


int main(int argc,char *argv[])
{
    int table[row][column]={
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

    int arrayOfValids[row*column];



    // int const Player= argv[9][0]-48;
    // defineTable(table,argv);
    validSquares(table1D,arrayOfValids,1);
    printTable(table);
    
    int i =0;
    while(arrayOfValids[i]!=-1){
        printf("%d\n",arrayOfValids[i]);
        i++;
    }



    
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

void defineTable(int table[row][column],char *argv[])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            table[i][j]= argv[i+1][j] - 48 ;
        }
    }

}

void printTable(int table[row][column]){
    puts("");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%d ",table[i][j]);
        }
        puts("");
    }

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
    for(int i =0;i<row*column;i++){
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