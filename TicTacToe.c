#include <stdio.h>

int check(char metrix[3][3], char symbol, int currentPlayer)
{
    for(int i=0; i<3; i++)
    {
        if(metrix[i][0] == symbol && metrix[i][1] == symbol && metrix[i][2] == symbol)
        {
             printf("Player %d wins\n", currentPlayer);
             return 0;
        }
        
    }
    for(int i=0; i<3; i++)
    {
        if(metrix[0][i] == symbol && metrix[1][i] == symbol && metrix[2][i] == symbol)
        {
             printf("Player %d wins\n", currentPlayer);
             return 0;
        }
        
    }
    if(metrix[0][0] == symbol && metrix[1][1] == symbol && metrix[2][2] == symbol)
        {
             printf("Player %d wins\n", currentPlayer);
             return 0;
        }
    
    if(metrix[2][0] == symbol && metrix[1][1] == symbol && metrix[0][2] == symbol)
        {
             printf("Player %d wins\n", currentPlayer);
             return 0;
             
        }
    
}

void printMatrix(char matrix[3][3])
{
    for(int i=0; i<3; i++)
    {
        printf("%c|%c|%c\n", matrix[0][i], matrix[1][i], matrix[2][i]);
        if(i != 2)
        printf("------\n");
    }
    printf("\n");
}

int main()
{
    char metrix[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    int currectPlayer = 1;
    char symbol = 'x';
    int x,y;
    
    while(1)
    {
        if(currectPlayer % 2 == 0)
        {
            symbol = 'x';
        }
        else
        {
            symbol = 'o';
        }

        printf("Player %d type coordinates\n", currectPlayer % 2);
        scanf("%d %d", &x, &y);
        printf("\n");

    

        if(metrix[x][y] == ' ')
        {
            metrix[x][y] = symbol;
        }
         else if(x > 2 || x > 2)
        {
            printf("coordinations ahve to be lower than 2!\n");
            currectPlayer--;
        }

        else
        {
            printf("field already occupied! Type again!\n");
            currectPlayer--;
        }


        int state = check(metrix,symbol,currectPlayer % 2);
        printMatrix(metrix);
        if(state == 0)
        {
            break;
        }
        if( currectPlayer == 9)
        {
            printf("It's a draw!\n");
            printMatrix(metrix);
            break;
        }
        currectPlayer++;
    }

    return 0;  
}