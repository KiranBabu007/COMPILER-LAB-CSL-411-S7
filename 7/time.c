#include<stdio.h>
#include<time.h>

void f1(){
    for(int i=0;i<5;i++){}
    printf("Helllo\n");
}

void f2(){
    printf("Helllo\n");
    printf("Helllo\n");
    printf("Helllo\n");
    printf("Helllo\n");
    printf("Helllo\n");
}



void main(){
    clock_t t1,t2;
    t1=clock();
    f1();
    t1=clock()-t1;
    printf("Time taken by loop: %f\n",(double)t1/CLOCKS_PER_SEC);

    t2=clock();
    f2();
    t2=clock()-t2;
    printf("Time taken by unrolled loop:%f\n",(double)t2/CLOCKS_PER_SEC);

}
