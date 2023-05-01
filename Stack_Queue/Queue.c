//
// Created by YOUChanWill on 2023/5/1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* pre;
} Node;


Node* initQueue() {
    Node* Q = (Node*)malloc(sizeof(Node));
    Q->data = 0;
    Q->pre = Q;
    Q->next = Q;
    return Q;
}

void enQueue(Node* Q, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = Q;
    node->pre = Q->pre;
    Q->pre->next = node;
    Q->pre = node;
    Q->data++;
}

int isEmpty(Node* Q) {
    if (Q->data == 0 || Q->next == Q) {
        return 1;
    } else {
        return 0;
    }
}

int deQueue(Node* Q) {
    if (isEmpty(Q)) {
        return 0;
    } else {
        Node* node = Q->next;
        Q->next = Q->next->next;
        Q->next->pre = Q;
        Q->data--;
        return node->data;
    }
}

void printQueue(Node* Q) {
    Node* node = Q -> next;
    while (node != Q) {
        printf("%d -> ", node -> data);
        node = node -> next;
    }
    printf("NULL\n");
}

int main() {
    Node* Q = initQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    printQueue(Q);
    printf("dequeue = %d\n", deQueue(Q));
    printf("dequeue = %d\n", deQueue(Q));
    printQueue(Q);
    return 0;
}