#include<stdio.h>
int main(){
int n;
printf("Enter the Number : ");
scanf("%d",&n);

int sum=0;
for(int i=1;i<=n;i++){
   sum += i;
}
printf("Value of first %d numbers are : %d",n,sum);
return 0;
}
