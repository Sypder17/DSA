#include<stdio.h>
int main(){
int n;
printf("Enter the number : ");
scanf("%d",&n);
int i = 1;
int sum = 0;
while(i == n){
  sum += i;
  i++;
}
printf("Sum of first %d is : %d",n,sum);
return 0;
}
