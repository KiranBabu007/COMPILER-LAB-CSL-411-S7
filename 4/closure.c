#include<stdio.h>
#include<string.h>

int cac(FILE*f,char state,char result[20][3]){
    char state1[3],input[3],state2[3];
    int count=1;
    strcpy(result[0],state);

    while(fcanf(f,"%s %s %s",state1,input,state2)!=EOF){
        if(strcmp(state1,state)==0 && strcmp(input,"e")==0){
            
        }

    }
}


int main(){
 char states[20][20],result[20][3],n;

 FILE *f;
 if(!f){
  printf("Error in opening file");
  return;
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

return 0;

}
