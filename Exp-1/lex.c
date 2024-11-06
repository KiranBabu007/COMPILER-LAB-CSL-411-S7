#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main() {
    char operators[] = "+-/*=<>";
    char buffer[100];
    char keywords[10][10] = { "if", "else", "printf", "while", "int", "char" };
    char c;

    FILE *f;

    f=fopen("lex.txt","r");
    

    if (!f){
        printf("File not found");
        return ;
    }

    while((c=fgetc(f))!=EOF){
        if(isalnum(c)){
            int i=0;
            while(isalnum(c)){
                buffer[i++]=c;
                c=fgetc(f);
            }
            buffer[i]='\0';
            ungetc(c,f);

        int iskey=0;
        for(int j=0;j<10;j++){
            if(strcmp(buffer,keywords[j])==0){
                printf("%s is a keyword\n",buffer);
                iskey=1;
            }
        }
        if(!iskey){
            printf("%s is an identifier\n",buffer);
            memset(buffer,0,100);
        }
    }
    else if(strchr(operators,c)){
        printf("%c is an operator\n",c);
    }
    else if(isspace(c)){
        continue;
    }
    else{
        printf("%c is a special character\n",c);
    }
    }

}
