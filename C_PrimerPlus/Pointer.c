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

// 计算int数组的元素总和
int sum(int * arr, int n){
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += arr[i]; // arr[i] == *(arr + 1)
    }
    return total;
}

int main(void){
    int ar[6] = {3,4,5,6,9,6};
    long answer = sum(ar,6);
    printf("The total is %d\n",answer);

    int x = 5, y = 10;
    printf("Originally x = %d and y = %d\n",x,y);
    interchange(&x,&y);
    printf("Now x = %d and y = %d\n",x,y);

    // 指针运算的优先级
    int *p1, *p2, *p3;






}
