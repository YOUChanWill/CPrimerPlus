//
// Created by YOUChanWill on 2023/4/30.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initList(){
    Node* L = (Node*)malloc(sizeof(Node));
    L -> data = 0;
    L -> next = L;
    return L;
}

void headInsert(Node* L, int data) {
    Node* node = (Node*)malloc(sizeof (Node));
    node->data = data;
    node->next = L->next;
    L->next = node;
    L->data++;
}

void tailInsert(Node* L, int data) {
    Node* n = L;
    Node* node = (Node*)malloc(sizeof (Node));
    node->data = data;
    while (n->next != L){
        n = n->next;
    }
    node->next = L;
    n->next = node;
}

int delete(Node* L, int data){
    Node* preNode = L;
    Node* node = L->next;
    while (node != L){
        if(node->data == data){
            preNode->next = node->next;
            free(node);
            return 1;
        }
        preNode = node;
        node = node->next;
    }
    return 0;
}


void printList(Node* list){
    Node* node = list->next;
    while (node != list){
        printf("%d->",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    Node* L = initList();
    headInsert(L,1);
    headInsert(L,2);
    headInsert(L,3);
    headInsert(L,4);
    tailInsert(L,5);
    tailInsert(L,6);
    printList(L);
    delete(L,1);
    delete(L,3);
    printList(L);
}
