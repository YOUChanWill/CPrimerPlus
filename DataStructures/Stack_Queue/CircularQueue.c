//
// Created by YOUChanWill on 2023/5/1.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 // 定义队列的长度

// 循环队列的实现使用数组
typedef struct Queue {
    int front;
    int rear;
    int data[MAXSIZE];
} Queue;

Queue* initQueue() {
    Queue* Q = (Queue*)malloc(sizeof(Queue)); // 内存中开辟新的空间
    Q->front = Q->rear = 0;
    return Q;
}

void printQueue(Queue* Q) {
    // 要知道队列当前有多少个元素
    int length = (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
    int index = Q->front;
    for (int i = 0; i < length; i++) {
        printf("%d -> ", Q->data[index]);
        index = (index + 1) % MAXSIZE;
    }
    printf("NULL\n");
}

int isFull(Queue* Q) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Queue* Q) {
    if (Q->front == Q->rear) {
        return 1;
    } else {
        return 0;
    }
}

int enQueue(Queue* Q, int data) {
    if (isFull(Q)) {
        return 0;
    } else {
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

int deQueue(Queue* Q) {
    if (isEmpty(Q)) {
        return -1;
    } else {
        int data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return data;
    }
}

int main() {
    Queue* Q = initQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);
    return 0;
}