#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}
int main(){
    int (*fptr[])(int,int)={add,sub,mul};
    printf("Add : %d\n",fptr[0](10,20));
    printf("Sub : %d\n",fptr[1](20,10));
    printf("Mul : %d\n",fptr[2](10,20));
}
