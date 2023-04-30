#include <stdio.h>
#include <stdlib.h>

// 定义链表结点
typedef struct Node {
    int data;
    struct Node* next;
}Node;

// 链表的初始化
Node* initList(){
    Node* list = (Node*)malloc(sizeof(Node)); // 为新结点开辟空间
    list -> data = 0;
    list -> next = NULL;
    return list;
}

// 头部插入
void headInsert(Node* list, int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = list -> next;
    list -> next = node;
    list -> data++;
}

// 尾部插入
void tailInsert(Node* list, int data){
    Node* head = list;
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    list = list -> next;

    while (list -> next){
        list = list -> next;
    }
    list -> next = node;
    head -> data++;
}

void delete(Node* list, int data){
    Node* pre = list;
    Node* current = list -> next;
    while (current){
        if(current -> data == data){
            pre -> next = current -> next;
            free(current);
            break;
        }
        pre = current;
        current = current -> next;
    }
    list -> data--;
}

// 遍历
void printList(Node* list){
    list = list -> next;
    while (list){
        printf("%d", list -> data);
        list = list -> next;
    }
    printf("\n");
}

int main() {
    Node* list = initList();
    printList(list);
    headInsert(list,1);
    headInsert(list,2);
    headInsert(list,3);
    headInsert(list,4);
    tailInsert(list,5);
    tailInsert(list,6);
    tailInsert(list,7);
    printList(list);
    delete(list,4);
    delete(list,1);
    printList(list);
    return 0;
}