#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int main(){
    int (*fptr)(int,int);//declaration
    fptr=add;
    int res=fptr(10,20);
    printf("Addition : %d\n",res);
    return 0;
}