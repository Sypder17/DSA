#include<stdio.h>
int main(){
int n;
printf("Enter the number : ");
scanf("%d",&n);
int count = 1;
int sumEven = 0;
int sumOdd = 0;
while(n!=0){
   
   //if my counter is divisible 2 its at even position
   if(count%2==0){
     sumEven += n%10;
   }
   else{
   sumOdd += n%10;
   }
    n = n/10;
   count++;
  }
printf("The Addition of the Even indexed in the number  : %d\n",sumEven);
printf("The Addition of the odd indexed in the number  : %d\n",sumOdd);
printf("%d",sumOdd);
return 0;
}
