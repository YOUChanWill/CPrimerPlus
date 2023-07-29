//
// Created by YOUChanWill on 2023/5/1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *initStack() {
    Node *L = (Node *)malloc(sizeof(Node));
    L->data = 0;
    L->next = NULL;
    return L;
}

void push(Node *L, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    L->next = node;
    L->data++;
}

int pop(Node *L) {
    if (L->data == 0) {
        return 0;
    } else {
        Node *node = L->next;
        int data = node->data;
        L->next = node->next;
        free(node);
        L->data--;
        return data;
    }
}

int isEmpty(Node *L) {
    if (L->data == 0 || L->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void printStack(Node *stack) {
    Node *node = stack->next;
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node *stack = initStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printStack(stack);
    printf("pop = %d\n", pop(stack));
    printStack(stack);
}