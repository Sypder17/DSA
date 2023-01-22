#include<stdio.h>
void pattern(int n)
{
    int i,j;
     
    // This is upper half of pattern
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=(2*n); j++)
        {
            // Left part of pattern
            if (i<j)
                printf(" ");
            else{
                 if((i+j)%2 == 0){
                    printf("1");
                }
                else{
                    printf("0");
                }
             }
            // Right part of pattern
            if (i<=((2*n)-j))
                printf(" ");
            else{
                if((i+j)%2 == 0){
                    printf("0");
                }
                else{
                    printf("1");
                }
        }
        }
        printf("\n");
    }
     }
 
 

int main()
{
    pattern(7);
    return 0;
}
