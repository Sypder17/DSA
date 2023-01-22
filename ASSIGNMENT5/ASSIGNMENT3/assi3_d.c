#include<stdio.h>
int main()
{
    int arr[]={2,5,6,1,5,7,8,2,6,10,12,3,4,1,33,8,9,2,4,1};
    int size = sizeof(arr)/sizeof(int);
    int sum=0;

    for(int i=0;i<size;i++)
    {
        sum+= (arr[i] % 2 == 0) ? arr[i] : 0;
    }
    printf("Sum of even elements :  %d\n",sum);
    return 0;

}
