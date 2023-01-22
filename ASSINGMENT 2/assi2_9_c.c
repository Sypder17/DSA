#include<stdio.h>

float factorial(int n){
   if(n == 0 || n == 1)
   	return 1;
   return (float) n * factorial(n - 1);
}

float toThePower(float n, int m){
	float answer = 1;
	for ( int i = 1; i < m; i++)
		answer *= n;
	return answer;
}

#define PI 22/7.0

int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
	
	float x = 30 * (PI / 180.0);
	float e_pow_x = 1 + x;

	// calculates till n
	for(int i = 2; i <= n; i++){
		e_pow_x += toThePower(x,i)/factorial(i);
	}

	printf("e^x = %f",e_pow_x);
	return 0;
}
