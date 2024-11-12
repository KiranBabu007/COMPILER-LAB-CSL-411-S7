#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char exp[80],postfix[80],stack[80];

int top=-1;

void push(char c){
    if(top<=80){
        printf("Stack Overflow\n");
    }
    stack[++top]=c;
}

void pop(){
    if(top<0){
        printf("Stack Underflow\n");
    }
    return stack[top--];
}

int precedence(char c){
    switch(c){
        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        return 2;

        default:
        return 0;
    }
}

int isoper(char t){
    return (t =="+" || t=="-" || t=="*" || t=="/");
}

void main(){
    printf("\t\n Intermediate Code Generation\n\n");
    printf("enter the expression");
    scanf("%s",exp);
    infixtopostfix();
    printf("The Intermediate Code is :");
    generatecode();
    return 0;
}