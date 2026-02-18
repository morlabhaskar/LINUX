#include<stdio.h>
int mul(int a,int b){
    return a*b;
}
int operate(int (*fptr)(int,int),int a,int b){
    return fptr(a,b);
}
int main(){
    int res=operate(mul,10,20);
    printf("Result : %d\n",res);
}
