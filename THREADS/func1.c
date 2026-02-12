/*
return_type (*pointer_name)(parameter_list);
*/
#include<stdio.h>
void print(int a){
    printf("Value is %d\n",a);
}
int main(){
    void (*fptr)(int);//declaration
    fptr=print;//assaign function address
    // fptr=&print;//also valid

    // *fptr(10);//function call
    (*fptr)(10);//also valid
}