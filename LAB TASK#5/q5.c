#include<stdio.h>
int main(){
    int ph;
    printf("Enter PH level");
    scanf("%d",&ph);
if(ph<0 || ph>14){
    return 0;
}
    if(ph>7){
        if(ph<12){
            printf("Alkaline");
            return 0;
        }
        else{
            printf("Very Alkaline");
            return 0;
        }
    }
    else{
        if(ph==7){
            printf("Neutral");
            return 0;
        }
        else{
            if (ph>2)
            {
                printf("Acidic");
                return 0;
            }
            else{
                printf("Very Acidic");
                return 0;
            }
        }
    }
}