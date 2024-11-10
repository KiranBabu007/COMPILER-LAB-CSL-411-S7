#include<stdio.h>
#include<string.h>

char op[2],arg1[5],arg2[5],result[5];
void main(){
FILE *f1,*f2;
char f[100];
f1=fopen("input.txt","r");
f2=fopen("output.txt","w");

while(fscanf(f1,"%s %s %s %s",op,arg1,arg2,result)!=EOF){
    
    if(strcmp(op,"+")==0){
        fprintf(f2,"MOV  R0,%s\n",arg1);
        fprintf(f2,"ADD R0,%s\n",arg2);
        fprintf(f2,"MOV %s,R0\n",result);
    }
    if(strcmp(op,"-")==0){
        fprintf(f2,"MOV  R0,%s\n",arg1);
        fprintf(f2,"SUB R0,%s\n",arg2);
        fprintf(f2,"MOV %s,R0\n",result);
    }
    if(strcmp(op,"*")==0){
        fprintf(f2,"MOV  R0,%s\n",arg1);
        fprintf(f2,"MUL R0,%s\n",arg2);
        fprintf(f2,"MOV %s,R0\n",result);
    }
    if(strcmp(op,"/")==0){
        fprintf(f2,"MOV  R0,%s\n",arg1);
        fprintf(f2,"DIV R0,%s\n",arg2);
        fprintf(f2,"MOV %s,R0\n",result);
    }
    if(strcmp(op,"=")==0){
        fprintf(f2,"MOV  R0,%s\n",arg1);
        fprintf(f2,"MOV %s,R0\n",result);
    }
}

fclose(f1);
fclose(f2);
getchar();


}