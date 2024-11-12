#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char expr[80],postfix[80],stack[80];

int top=-1;

void push(char c){
    if(top>=80){
        printf("Stack Overflow\n");
    }
    stack[++top]=c;
}

char pop(){
    if(top<0){
        printf("Stack Underflow\n");
        return '\0';
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
    return (t =='+' || t=='-' || t=='*' || t=='/');
}

void infixtopostfix(){
    int i,j;
    char c;
    for(i=0 , j=0 ; expr[i] != '\0' ; i++){
       if(isalnum(expr[i])){
        postfix[j++]=expr[i];
       }
       else if(expr[i]=='('){
        push(expr[i]);
       }
       else if(expr[i]==')'){
        while((c=pop())!='('){
            postfix[j++]=c;
        }
       }
       else if(isoper(expr[i])){
        while(top>=0&&precedence(stack[top])>=precedence(expr[i])){
            postfix[j++]=pop();
        }
        push(expr[i]);
       }
    }
    while(top>=0){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

void generatecode(){
    char operandstack[80][2];
    char temp='Z';
    int operand_top=-1;

    for(int i=0;postfix[i]!='\0';i++){
        if(isalnum(postfix[i])){
            operand_top++;
            operandstack[operand_top][0]=postfix[i];
            operandstack[operand_top][1]='\0';
        }
        else{
            char right[2],left[2];
            strcpy(right,operandstack[operand_top--]);
            strcpy(left,operandstack[operand_top--]);

            printf("\t%c:%s %c %s\n",temp,left,postfix[i],right);

            operand_top++;
            operandstack[operand_top][0]=temp;
            operandstack[operand_top][1]='\0';
            temp--;
        }
    }
}

int main(){
    printf("\t\n Intermediate Code Generation\n\n");
    printf("enter the exprression");
    scanf("%s",expr);
    infixtopostfix();
    printf("The Intermediate Code is :\n");
    generatecode();
    return 0;
}