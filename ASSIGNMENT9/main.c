#include<stdio.h>
#include"stack.h"
#include<stdlib.h>




int evaluatePostfix(stack *s, char *postfix, int size){
    int eval=0;
    for(int i=0;i<size;i++){
        char c = postfix[i];
       
        if(!(c == '+' || c == '-' || c == '*' || c == '/')){
            push(s,c);
        }
        else {
            int b = pop(s) - '0';
            int a = pop(s) - '0';
            printf("%d\t%d\n",a,b);
            switch(c){
                case '+': 
                        eval = a+b;
                        break;
                case '-':
                        eval = a-b;
                        break;
                case '*':
                        eval = a*b;
                        break;
                case '/':
                        eval = a/b;
                        break;
            }
            push(s,eval + '0');
        }
    }

    return eval;
}

void printExpression(char *expr, int size){
    for(int i=0;i<size;i++){
        printf("%c",expr[i]);
    }
}

int main(){
    char postfix[]="123/32**+1+";
    int size = sizeof(postfix) / sizeof(char);
    stack s;
    initStack(&s,size);

    printExpression(postfix,size);
    

    printf("\n is %d\n",evaluatePostfix(&s,postfix, size-1));



    return 0;
}
