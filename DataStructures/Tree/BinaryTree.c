//
// Created by YOUChanWill on 2023/5/2.
//
#include <stdio.h>
#include <stdlib.h>

// 树的定义s
typedef struct TreeNode {
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

// 创建一棵树
void createTree(TreeNode** T, char* data, int* index) {
    char ch;
    ch = data[*index];
    *index += 1;
    if (ch == '#') {
        // 此时为空节点
        *T = NULL;
    }
    else {
        // 此时不为空
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T) -> data = ch;
        // 创建左子树，逻辑一致，进行递归
        createTree(&((*T)->lchild), data, index);
        // 创建右子树，逻辑一致，进行递归
        createTree(&((*T)->rchild), data, index);
    }
}

// 树的前序遍历
void preOrder(TreeNode* T) {
    if (T == NULL) {
        return;
    }
    else {
        // 先办事
        printf("%c ", T->data);
        // 处理左孩子
        preOrder(T->lchild);
        // 处理右孩子
        preOrder(T->rchild);
    }
}

// 树的中序遍历
void inOrder(TreeNode* T) {
    if (T == NULL) {
        return;
    }
    else {
        // 处理左孩子
        inOrder(T->lchild);
        // 中办事
        printf("%c ", T->data);
        // 处理右孩子
        inOrder(T->rchild);
    }
}

// 树的后序遍历
void postOrder(TreeNode* T) {
    if (T == NULL) {
        return;
    }
    else {
        // 处理左孩子
        postOrder(T->lchild);
        // 处理右孩子
        postOrder(T->rchild);
        // 后办事
        printf("%c ", T->data);
    }
}

int main(int argc, char* argv[]) {
    TreeNode* T;
    int index = 0;
    createTree(&T, argv[1], &index);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");
    return 0;
}