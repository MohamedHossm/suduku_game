#include <windows.h>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
#define  SSize 81
int i = 0,j = 0,state = 0 ;
void SetColor(int ForgC);
int main()
{
    char SolveData [9][10]  =
    {
        "256837149",
        "719425836",
        "843619257",
        "467158923",
        "392764518",
        "581392674",
        "178246395",
        "635971482",
        "924583761"
    };
    char Data [9][10]  =
    {

        "256837149",
        "719425836",
        "843619257",
        "467158923",
        "392764518",
        "581392674",
        "178246395",
        "635971482",
        "924583761"
    };
    long long  t;
    srand((unsigned) time(&t));
    instructions();
    Genrateblank(Data,3);
    int SearchArr[SSize] = {0} ;
    int ele =  CSerchArr(SearchArr,Data, 9);

    while (checkSolv(SolveData,Data,9) == 1&&state==2)
    {
        SetColor(15);
        printf(" Up    : W \n Down  : S \n Right : D \n Left  : A \n\n", i, j );
        print2D_Array(Data,SearchArr,ele,9);
        movementOnGrid(Data,SearchArr, ele);
        system("cls") ;
    }
    End ();
}

