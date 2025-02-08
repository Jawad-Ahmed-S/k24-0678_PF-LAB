#include <stdio.h>

void multiplyMatrices(int a[3][3], int b[3][3], int Multiplication[3][3]);

void Subtraction(int a[3][3], int b[3][3], int subtract[3][3]);
int main()
{
    int MatrixA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int MatrixB[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    int Multiplication[3][3] = {0};
    int Subtract[3][3] = {0};

    multiplyMatrices(MatrixA, MatrixB, Multiplication);
    Subtraction(MatrixA, MatrixB, Subtract);

    printf("Multiplication: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", Multiplication[i][j]);
        }
        printf("\n");
    }
    printf("Subtraction: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", Subtract[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void multiplyMatrices(int a[3][3], int b[3][3], int multiplied[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                multiplied[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void Subtraction(int a[3][3], int b[3][3], int subtract[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            subtract[i][j] = (a[i][j] - b[i][j]);
        }
    }
}