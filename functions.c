#include <windows.h>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
extern int state;
extern int i,j ;

void SetColor(int ForgC)
{
    WORD wColor;
    //This handle is needed to get the current background attribute

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //csbi is used for wAttributes word

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void Genrateblank(char ptr[][10], int num)
{
    int posx = 0 ;
    int posy = 0 ;
    for (int iin = 0 ; iin < num ; iin++ )
    {
        posx = rand( )%9 ;
        posy = rand( )%9  ;
        // printf("%d %d ",posx,posy);
        ptr[posx][posy] = '#' ;
    }
}
void End ()
{
    if (state == 0 )
    {
        printf("\n\n\n\t\t\tSee u later \n\n\n");
    }
    else if (state == 1 )
        printf("\n\n\n\t\t\tCongrats u did it \n\n\n");
    getch ();
}
int BinarySearch(int *arr,int index, int size  )
{
    int L = 0 ;
    int R = size -1 ;
    int mid = 0 ;
    while (L<=R )
    {
        mid = (R +L)/2 ;
        if (arr[mid] ==index )
        {
            return 1 ;
        }
        else  if (arr[mid] >index )
        {
            R = mid-1 ;
        }
        else if (arr[mid] <index )
        {
            L = mid +1 ;
        }
    }
    return 0 ;
}
int checkSolv(char (*ptr)[10], char (*ptr1)[10],int size  )
{
    for (int iin = 0 ; iin <size ; iin ++ )
    {
        for (int jin = 0 ; ptr[iin][jin]|| ptr1[iin][jin] ; jin ++)
        {
            if (ptr[iin][jin]!= ptr1[iin][jin])
            {
                return 1 ;
            }
        }
    }
    state = 1 ;
    return 0  ;
}

void  print_Array(int *arr, int size )
{
    for (int ind_i = 0 ; ind_i< size ; ind_i++)
    {
        printf("%d ",arr[ind_i] );
    }
    printf("\n");
}
int  CSerchArr(int *arr, char (*arr1)[10], int Row)
{
    int indexSearch = 0 ;
    int ini,inj ;
    for ( ini = 0 ; ini< Row; ini++ )
    {
        for (inj = 0 ; arr1[ini][inj]; inj++)
        {
            if (arr1[ini][inj]!='#')
            {
                arr[indexSearch] = (ini*10) +inj ;
                indexSearch++ ;
            }
        }
    }
    return indexSearch  ;
}
void movementOnGrid(char (*arr)[10], int *data, int size )
{
    unsigned char c = 0 ;
    fflush(stdin) ;
    c = getch() ;
    //printf("%d",c);
    if (c=='w'||c=='W')
        i-- ;
    else if(c=='a'||c=='A')
        j-- ;
    else if(c=='S'||c=='s')
        i++ ;
    else if(c=='d'||c=='D')
        j++ ;
    if ( i <0) i = 0 ;
    if ( j <0) j = 0 ;
    if ( i >=8) i = 8 ;
    if ( j >=8) j = 8 ;
    if (c>='1'&&c<='9')
    {
        if (BinarySearch (data, (i*10)+j, size)==1)
        {
            // printf("inVlalid");
        }
        else
            arr[i][j] = c ;
    }
    else if (c==27)
    {
        state = 0 ;

    }
}
void Set2D_Array_S ( char (*arr)[10], int Row,int Col )
{
    int x = 0, y = 0 ;
    if (Row >= 0 && Row <= 8&&Col >= 0 && Col <=8)
    {
        x = Row  ;
        y = Col ;
    }
    else
    {
        return ;
    }
    arr[x][y] =' ' ;
}
void print2D_Array ( char (*arr)[10],int * data, int size, int Row )
{
    int ini,inj ;
    for ( ini = 0 ; ini< Row; ini++ )
    {
        printf("   ");
        if (ini%3==0 )
        {
            SetColor(15);
            printf("-------------------------------\n");
            printf("   ");
        }
        for (inj = 0 ; arr[ini][inj]; inj++)
        {
            if (inj%3==0 )
            {
                SetColor(15);
                printf("|");
            }
            if(ini == i&& inj==j)
            {
                SetColor(12);
                printf("[%c]",arr[ini][inj]);
            }
            else
            {
                if (BinarySearch (data, (ini*10)+inj, size)==1)
                {
                    SetColor(19);
                    printf(" %c ",arr[ini][inj]);

                }
                else
                {
                    SetColor(15);
                    printf(" %c ",arr[ini][inj]);

                }


            }
            if (inj==8 )
            {
                SetColor(15);
                printf("|");
            }
        }
        SetColor(15);
        printf("\n");
    }
    SetColor(15);
    printf("   ");
    printf("-------------------------------\n");
}
void instructions()
{
    printf("\n \t\t\tinstructions \n");
    printf("  1- use the following keys to move in suduku grid \n");
    printf("  2- u can only change wight blocks\n");
    printf("  3- u can close the program any time by presing [ESC]\n");
    printf("  press [Enter] to continue \n  press ESC] to Exit\n");
    state=getch();
    //  printf("%d",state);
    if (state ==13)
    {
        state = 2;
        system("cls") ;

    }
    else if ( state ==27)
    {
        state = 0 ;
        system("cls") ;
    }
    else
    {
        system("cls") ;
        instructions();

    }

}

