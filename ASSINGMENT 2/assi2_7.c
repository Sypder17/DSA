#include<stdio.h>
#include<stdlib.h>

int gcd(int smallerNumber, int greaterNumber){
	int gcd = 1;
	
	for(int i = 2; i <= smallerNumber; i++){
		if(smallerNumber % i == 0 && greaterNumber %i == 0)
			gcd = i;
	}
	
	return gcd;
}

int lcm(int smallerNumber, int greaterNumber){
	int lcm = 0;
	int smallerNumberMultiple = smallerNumber;
	int greaterNumberMultiple = greaterNumber;
	
	while(smallerNumberMultiple != greaterNumberMultiple){
		if(smallerNumberMultiple < greaterNumberMultiple){
			smallerNumberMultiple += smallerNumber;
		}else{
			greaterNumberMultiple += greaterNumber;
		}
	}
	
	lcm = smallerNumberMultiple;
	return lcm;
}

int main(){
   
   int smallerNumber , greaterNumber;
   printf("Enter the smaller Number : ");
   scanf("%d",&smallerNumber);
   
   printf("Enter the greaterNumber : ");
   scanf("%d", &greaterNumber);
   
   printf("Value of GCD is : %d \n",gcd(smallerNumber , greaterNumber));
   printf("Value of LCM is : %d \n",lcm(smallerNumber , greaterNumber));
 
return 0;


}
