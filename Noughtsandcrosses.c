/*int a[3][3]
   0 1 2
0  0,0|0,1|0,2
1  1,0|1,1|1,2
2  2,0|2,1|2,2

*/
#include<stdio.h>
//#include<stdlib.h>
void display_board(char a[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            
            printf(" %c ",a[i][j]);
            
            if(j<2)
            {
                printf("|");
            }
            
        }
        printf("\n");
        if(i<2)
        {
            printf("___+___+___\n");
        }
    }
}
int check_winner(char a[3][3],char cp)
{
    for(int i=0;i<3;i++)
        {
            if(a[i][0]==cp && a[i][1]==cp && a[i][2]==cp)
            {
                return 1;
            }
            if(a[0][i]==cp&& a[1][i]==cp && a[2][i]==cp)
            {
                return 1;
            }
        }
        if(a[0][0]==cp&&a[1][1]==cp&&a[2][2]==cp)
        {
            return 1;
        }
        if(a[0][2]==cp && a[1][1]==cp && a[2][0]==cp)
        {
            return 1;
        }
        return 0;
}
int main(void)
{
    char a[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char cp='X';
    int i=0,r,c;//to count moves
    while(1)
    {
        printf("\nPlayer %c Now your Turn ",cp);
        printf("\nEnter row(0-2)and column(0-2) seperated by space ");
        scanf("%i %i",&r,&c);
        if(r<0 || r>2 || c<0 || c>2 || a[r][c]!=' ')
        {
            printf("\nInvalid Position\nTry Again...");continue;
        }
        
        a[r][c]=cp;
        i++;
//        system("cls");
        display_board(a);
        if(check_winner(a,cp))
        {
            printf("Player %c Wins!!!!\n",cp);break;
        }
        else if(i==9)
        {
            printf("\nIt's a Draw!!!!");break;
        }
        
        cp=(cp=='X')?'O':'X';//toggle case player X- Player O vice versa
        
        
        
    }
    
}


