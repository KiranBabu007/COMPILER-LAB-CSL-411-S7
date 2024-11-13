#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int calc(FILE *f,char state[],char result[20][3]){
    char initial[3],state1[3],op[3],state2[3];
    strcpy(result[0],state);
    strcpy(initial,state);
    int count=1;

    while(fscanf(f,"%s %s %s",state1,op,state2)!=EOF){
        if(strcmp(state1,initial)==0 && strcmp(op,"e")==0){
            strcpy(result[count],state2);
            strcpy(initial,state2);
            count++;
        }
    }

    return count;
}

void display(char st[],char res[20][3],int count){
    printf("The Closure  of state %s is:",st);
    for(int i=0;i<count;i++){
        printf("%s ",res[i]);
    }
}


void main(){

char states[20][3],result[20][3];

FILE *f;
int n;

f=fopen("input.dat","r");

printf("Enter the no of states:");
scanf("%d",&n);

printf("Enter the states");

for(int i=0;i<n;i++){
    scanf("%s",states[i]);
}

for(int i=0;i<n;i++){
    int count=calc(f,states[i],result);
    display(states[i],result,count);
    rewind(f);
}




}