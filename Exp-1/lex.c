#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void main(){
    char operators[]="+-/*=<>";
    char buffer[100];
    char keywords[10][10]={"if","else","printf","while","int","char"};

    int bindex=0;


    FILE *f;

    f=fopen("lex.txt","r");
    fgets(buffer,sizeof(buffer),f);
    printf("Content of the file:%s\n",buffer);
    bzero(buffer,100);
    fclsoe(f);

    f=fopen("lex.txt","r");
    printf("Output:");

    while(1){
     char c=getc(f);
     if(feof(f))
     break;

     if(isalnum(c)){
        buffer[bindex++]=c;
        while(isalnum(c=fgetc(f))){
            buffer[bindex++]=c;
        }
     }
     buffer[bindex]="\0";
     ungetc(c,f);
    int is_key=0;
     for(int i=0;i<10;i++){
        if(strcmp(buffer,keywords[i]==0)){
            printf("%s is a keyword\n",buffer);
            is_key=1;
            break;
        }
     }

        if(!is_key){
            printf("%s is an identifer\n",buffer);
        }
        bindex=0;
     

     if(strchr(operators,c)){
        printf("%c is an operator\n",c);
     }
     else if(isspace(c)){
        continue;
     }
     else{
        printf("%c is a special symbol");}
    }
     }





    

