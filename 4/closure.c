#include<stdio.h>
#include<string.h>

int calc(FILE*f,char state[],char result[20][3]){
    char initial[3],state1[3],input[3],state2[3];
    int count=1;
    strcpy(initial,state);
    strcpy(result[0],state);
    while(fscanf(f,"%s %s %s",state1,input,state2)!=EOF){
        if(strcmp(state1,initial)==0 && strcmp(input,"e")==0){
            strcpy(result[count],state2);
            strcpy(initial,state2);
            count++;
        }
    }
    return count;
}

void display(char state[],char result[20][3],int count){
    printf("\nThe Closure of state %s is:",state);
    for(int i=0;i<count;i++){
        printf("%s ",result[i]);
    }
}

int main(){
 char states[20][3],result[20][3];
 int n;

 FILE *f;
 f=fopen("input.dat","r");
 if(!f){
  printf("Error in opening file");
  return 1;
 }
 printf("Enter the number of states:");
 scanf("%d",&n);

 printf("Enter the states:");

 for(int i=0;i<n;i++){
    scanf("%s",states[i]);
 }

 for(int i=0;i<n;i++){
    int count=calc(f,states[i],result);
    display(states[i],result,count);
    rewind(f);
 }
fclose(f);
return 0;

}
