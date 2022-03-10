#include<stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef struct node{
    int data;
    struct node* next;
}Node;

//头插法插入结点
Node* init_HeadInsert(Node* head){
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    for(int i=1;i<=MaxSize;i++){
        Node* p = (Node*)malloc(sizeof(Node));
        p->data = i;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

//未插入插入结点
Node* init_TailInsert(Node* head){
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* temp = head;
    for(int i = 1;i<=MaxSize;i++){
        Node* p = (Node*)malloc(sizeof(Node));
        p->data = i;
        temp->next = p;
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

/*
 * 链表反转实现
 */
void tailInsert_reverseLinkList(Node* head){
    Node* p = head->next;
    Node* temp1,*temp2 = head;
    while(p != NULL){
        temp1 = temp2->next;
        temp2->next = temp1;
        p = p->next;
    }
    p->next = NULL;
}

//按照指定位置插入结点
void insertNode(Node* head,int pos,int x){
    Node* p = head;
    for(int i = 1;i<pos;i++){
        p = p->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

//打印结点
void printNode(Node* head){
    Node* p = head->next;
    int i = 0;
    while(p != NULL){
        i++;
        printf("%d\n",p->data);
        p = p->next;
    }
}

//测试
int main(){
    Node* arrList;
    Node* head = init_HeadInsert(arrList);
    printNode(head);
    printf("pretend a spilt line\n");
    tailInsert_reverseLinkList(head);
//  insertNode(head,6,13);
//  Node* head = init_TailInsert((arrList));
    printNode(head);
}

