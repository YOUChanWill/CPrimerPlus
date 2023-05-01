//
// Created by YOUChanWill on 2023/5/1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* pre;
    struct Node* next;
} Node;

// 循环双向链表的初始化中前驱结点跟后继结点的指针都指向的是自身
Node* initList() {
    Node* L = (Node*)malloc(sizeof(Node));
    L->data = 0;
    L->pre = L;
    L->next = L;
    return L;
}

void headInsert(Node* L, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    node->pre = L;
    L->next->pre = node;
    L->next = node;
    L->data++;
}

void tailInsert(Node* L, int data) {
    Node* node = L;
    while (node->next != L) {
        node = node->next;
    }
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->pre = node;
    n->next = L;
    L->pre = n;
    node->next = n;
    L->data++;
}

int delete (Node* L, int data) {
    Node* node = L->next;
    while (node != L) {
        if (node->data == data) {
            node->pre->next = node->next;
            node->next->pre = node->pre;
            free(node);
            L->data--;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void printList(Node* L) {
    Node* node = L->next;
    while (node != L) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* L = initList();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 4);
    headInsert(L, 5);
    printList(L);
    tailInsert(L, 6);
    tailInsert(L, 7);
    printList(L);
    delete (L, 7);
    printList(L);
    return 0;
}