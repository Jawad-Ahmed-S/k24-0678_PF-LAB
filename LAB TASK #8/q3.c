#include <stdio.h>
int main()
{
    int array[5][5] = {{2, 3, 4, 5, 46},
                       {5, 6, 4, 5, 7},
                       {2, 6, 100, 5, 46},
                       {5, 6, 8, 5, 49},
                       {4, 6, 4, 4, 46}};

    int rowmax, colmin, saddlepoint = 0;
    int Index_rowmax, Index_colmin;

    for (int i = 0; i < 5; i++)
    {
        rowmax = array[i][0];
        for (int j = 0; j < 5; j++)
        {
            if (array[i][j] > rowmax)
            {
                rowmax = array[i][j];
                Index_rowmax = j;
            }
        }
        for (int m = 0; m < 5; m++)
        {
            colmin = array[0][Index_rowmax];
            if (array[m][Index_rowmax] < colmin)
            {
                colmin = array[m][Index_rowmax];
                Index_colmin = m;
                saddlepoint = 1;
            }
        }
    }
    if (saddlepoint == 1)
    {
        printf("Saddle point at %d at %d , %d", array[Index_colmin][Index_rowmax], Index_colmin, Index_rowmax);
    }
    else
    {
        printf("NO Saddle.");
    }
    return 0;
}
