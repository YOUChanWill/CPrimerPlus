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

// 双向链表的定义，设定前驱结点跟后继结点
Node* initList() {
    Node* L = (Node*)malloc(sizeof(Node));
    L->data = 0;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

// 在链表的头部插入只需要改变后继结点的位置
void headInsert(Node* L, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    node->pre = L;
    if (L->next) {
        L->next->pre = node;
        L->next = node;
    } else {
        L->next = node;
    }
}

void tailInsert(Node* L, int data) {
    Node* node = L;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    while (node->next) {
        node = node->next;
    }
    n->next = node->next;
    node->next = n;
    n->pre = node;
    L->data++;
}

int delete (Node* L, int data) {
    Node* node = L->next;
    while (node) {
        if (node->data == data) {
            node->pre->next = node->next;
            if (node->next) {
                node->next->pre = node->pre;
            }
            L->data--;
            free(node);
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void printList(Node* L) {
    Node* node = L->next;
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* L = initList();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    tailInsert(L, 5);
    tailInsert(L, 6);
    printList(L);
    delete (L, 6);
    printList(L);
    return 0;
}

