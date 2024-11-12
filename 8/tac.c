#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char expr[80];
char postfix[80];
char stack[80];
int top = -1;
void infix_to_postfix();
void generate_intermediate_code();
void push(char);
char pop();
int precedence(char);
int is_operator(char);

int main() {
printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
printf("Enter the Expression: ");
scanf("%s", expr);
infix_to_postfix();
printf("The postfix expression: %s\n", postfix);
printf("The intermediate code:\n");
generate_intermediate_code();
return 0;
}
void push(char c) {
if (top >= 80 - 1) {
printf("Stack overflow\n");
exit(1);
}
stack[++top] = c;
}
char pop() {
if (top < 0) {
printf("Stack underflow\n");
exit(1);
}
return stack[top--];
}
int precedence(char op) {
switch (op) {case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
default:
return 0;
}
}
int is_operator(char c) {
return (c == '+' || c == '-' || c == '*' || c == '/');
}
void infix_to_postfix() {
int i, j;
char c;
for (i = 0, j = 0; expr[i] != '\0'; i++) {
if (isalnum(expr[i])) {
postfix[j++] = expr[i];
} else if (expr[i] == '(') {
push(expr[i]);
} else if (expr[i] == ')') {
while ((c = pop()) != '(') {
postfix[j++] = c;
}
} else if (is_operator(expr[i])) {
while (top >= 0 && precedence(stack[top]) >= precedence(expr[i])) {
postfix[j++] = pop();
}
push(expr[i]);
}
}
while (top >= 0) {
postfix[j++] = pop();
}
postfix[j] = '\0';
}
void generate_intermediate_code() {
char operand_stack[80][2];
int operand_top = -1;
char temp = 'Z';
for (int i = 0; postfix[i] != '\0'; i++) {
if (isalnum(postfix[i])) {
operand_top++;
operand_stack[operand_top][0] = postfix[i];
operand_stack[operand_top][1] = '\0';
} else if (is_operator(postfix[i])) {
char right[2], left[2];strcpy(right, operand_stack[operand_top--]);
strcpy(left, operand_stack[operand_top--]);
printf("\t%c := %s %c %s\n", temp, left, postfix[i], right);
operand_top++;
operand_stack[operand_top][0] = temp;
operand_stack[operand_top][1] = '\0';
temp--;
}
}
}