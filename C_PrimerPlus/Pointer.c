//
// Created by YOUChanWill on 2023/5/3.
//
#include <stdio.h>

void interchange(int * u, int * v){
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}

int main(void){

    int x = 5, y = 10;
    printf("Originally x = %d and y = %d\n",x,y);
    interchange(&x,&y);
    printf("Now x = %d and y = %d\n",x,y);

}
