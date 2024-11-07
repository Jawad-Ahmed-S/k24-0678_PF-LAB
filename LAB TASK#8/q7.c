#include <stdio.h>

int main()
{
    int rows = 4;    // Number of rows for the triangle
    int repeats = 3; // Number of times to repeat horizontally

    for (int i = 0; i < rows; i++)
    {
        // Print each row for all triangles
        for (int r = 0; r < repeats; r++)
        {
            // Calculate the gap for this row
            int gap = 5 - i; // Initial gap
            // Print leading spaces for the current triangle
            for (int j = 0; j < (rows - i - 1) + (r * (gap + 1)); j++)
            {
                printf(" ");
            }

            // Print stars and spaces for the current row
            for (int j = 0; j <= i; j++)
            {
                if (j > 0)
                {
                    // Add extra spaces after odd-numbered stars
                    int extraSpaces = (i + 1) % 2 == 1 ? (j * 2) : 0;
                    for (int k = 0; k < gap + extraSpaces; k++)
                    {
                        printf(" ");
                    }
                }
                // Print stars at the edges
                if (j == 0 || j == i)
                {
                    printf("*");
                }
            }
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}
