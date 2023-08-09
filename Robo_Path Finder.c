#include <stdio.h>
#include <stdlib.h>

void down(int *b, int *a, int *c)
{
    ++b[0];
    ++*a;
    printf("ROBOT MOVED DOWN TO==>");
    printf("[%d] [%d]", *a, *c);
    printf("\n\n\n");
}
void right(int *b, int *a, int *c)
{
    ++b[1];
    ++*c;
     printf("ROBOT MOVED RIGHT TO==>");
    printf("[%d] [%d]", *a, *c);
    printf("\n\n\n");
}
void up(int *b, int *a, int *c)
{
    --b[0];
    --*a;
     printf("ROBOT MOVED UP TO==>");
    printf("[%d] [%d]", *a, *c);
    printf("\n\n\n");
}
void left(int *b, int *a, int *c)
{
    --b[1];
    --*c;
    printf("ROBOT MOVED LEFT TO==>");
    printf("[%d] [%d]", *a, *c);
    printf("\n\n\n");
}
void getendposition(int *endposition, int a, int b)
{
    int c1 = 0, c2 = 0;
    do
    {
        ++c1;
        if (c1 >= 2)
        {
            printf("please enter again with valid input\n");
        }
        printf("Enter the coordinate for row\n");
        scanf("%d", &endposition[0]);
    } while (endposition[0] > a - 2);
    do
    {
        ++c2;
        if (c2 >= 2)
        {
            printf("please enter again with valid input\n");
        }
        printf("Enter the coordinate for coloumn\n");
        scanf("%d", &endposition[1]);
    } while (endposition[1] > b - 2);

    printf("\n\nThe destination entered is [%d]\t[%d]\n\n", endposition[0], endposition[1]);
}
void welcome()
{
    printf("\n\n");
   
    printf("**** A STAR EXPLORER*****\n\n\n");
   
}
int main()
{
    welcome();
    int x, y;
    int i, j, k, l = 0, count1 = 0, count2 = 0;

    printf("Please add  2  extra rows and columns for every matrix\n\n");
    printf("press 1 for free space and press 0 for object in that cell of the matrix\n\n");
    
    printf("Enter the number of rows:");
    scanf("%d", &x);
     printf("\n");
    printf("Enter  the number of columns:");
    scanf("%d", &y);
     printf("\n\n");

    int M[x][y];
    
    for(i=1;i<=x-2;i++)
    {
        for(j=1;j<=y-2;j++)
        {
           
            printf("enter the element[%d][%d]:\n",i,j);
            scanf("%d", &M[i][j]);
        }
    }
    
    
    for (i = 0; i < x; i++)
    {
        M[i][0] = 0;
    }
    for (j = 0; j < y; j++)
    {
        M[0][j] = 0;
    }
    for (i = 0; i < x; i++)
    {
        M[i][y - 1] = 0;
    }
    for (j = 0; j < y; j++)
    {
        M[x - 1][j] = 0;
    }
    
    
    // Printing the array before fixing ENDPOSITION
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    // getting  ENDPOSITION from user.
    printf("While giving input for endposition consider your matrix....\n\n");
    int endposition[2];
    printf("Enter Coordinates for the endposition\n");
    getendposition(endposition, x, y);
    M[endposition[0]][endposition[1]] = 2;

    // Printing the array after fixing  ENDPOSITION
    printf("The endposition you mentioned will be shown as 2\n\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
   
    printf("\n");
    printf("\n");

    int B[2] = {1, 1}; // initialising Robot at Starting Point
    i = j = 1;
    printf("Press 1 for the robot to start moving\n\n");
    scanf("%d", &k);
    if (k == 1)
    {
        do
        {
            if (M[i + 1][j] != 0)
            {
                down(B, &i, &j);
                count1++;
                if (count1 > x - 2) // the maximum number of times it can be called
                {
                    printf("There exists no path\n");
                    break;
                }
            }

            else if (M[i][j + 1] != 0)
            {
                right(B, &i, &j);
                count2++;
                if (count2 > x - 2) //the maximum number of times it can be called
                {
                    printf("There exists no path\n");
                    break;
                }
            }
            else if (M[i][j - 1] == 1)
            {
                left(B, &i, &j);
            }
            else if (M[i - 1][j] == 1)
            {
                up(B, &i, &j);
            }
            else
            {
                printf("No paths found.\n");
                break;
            }
        } while (M[i][j] != 2);
    }
    else
    {
        printf("the robot has not started to move\n");
    }
    printf("Final Position: [%d]\t[%d]\n\n", B[0], B[1]);
    if (endposition[0] == B[0] && endposition[1] == B[1])
    {
        printf("THE ROBOT HAS REACHED THE ENDPOSITION\n\n\n");
    }
    else
    {
        printf("THE ROBOT HASN'T REACHED THE ENDPOSITION\n\n\n");
    }
    printf("*****THANK YOU FOR USING STAR EXPLORER******");
   
    return 0;
}
