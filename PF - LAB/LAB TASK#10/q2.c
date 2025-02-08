#include <stdio.h>
#include <math.h>
    struct Position
    {
        int x;
        int y;
    };
int InBoundary(struct Position Boundary,int x,int y){
    if(x>Boundary.x || y>Boundary.y){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{

    struct Position P[2] = {
        {2, 10},
        {45, 5},
    };
    
    int distance = sqrt(pow((P[1].x - P[0].x), 2) + pow((P[1].y - P[0].y), 2));
    printf("Distance between the points : %d \n ", distance);
    struct Position Boundary={10,10};
    int Point1 =InBoundary(Boundary,P[0].x,P[0].y);
    int Point2 =InBoundary(Boundary,P[1].x,P[1].y);
printf("Point 1 is in Boundary : %s \n",(Point1==0)?"Yes":"No");
printf("Point 2 is in Boundary : %s \n",(Point2==0)?"Yes":"No");
    
    return 0;
}