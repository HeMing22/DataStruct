
#include<stdio.h>
#include<stdlib.h>

typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

typedef struct LinkQueue{
    QNode *front,*rear;
} LinkQueue;

void initQueue_Head(LinkQueue &Q){
    printf("init\n");

    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    Q.front->next = NULL;
}

void enQueue_Head(LinkQueue &Q,int val){
    printf("en\n");

    QNode *node = (QNode*)malloc(sizeof(QNode));
    node->data = val;
    node->next = NULL;
    Q.rear->next = node;
    Q.rear = node;
}

int deQueue_Head(LinkQueue &Q){
    printf("de\n");

    int elem;
    QNode *p = Q.front->next;
    elem = p->data;
    Q.front->next = p->next;

    // 当尾指针等于头指针指向的下一个结点时，说明队列为空，此时应让头指针等于尾指针，然后删除出队元素，回归初始态
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    printf("de wal\n");

    return elem;
}

bool isEmpty(LinkQueue &Q){
    return Q.rear == Q.front;
}


void initQueue_NoHead(LinkQueue &Q){
    Q.rear = NULL;
    Q.front = NULL;
}

void enQueue_NoHead(LinkQueue &Q,int val){
    QNode *node = (QNode*)malloc(sizeof(QNode));
    node->data = val;
    node->next = NULL;
    if(Q.front == NULL){
        Q.front = node;
        Q.rear = node;
    }else{
        Q.rear->next = node;
        Q.rear = node;
    }
}

int deQueue_NoHead(LinkQueue &Q){
    int elem;
    if(Q.front == NULL){
        return -1;
    }

    QNode* p = Q.front;
    elem = p->data;
    Q.front = Q.front->next;
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    free(p);
    return elem;
}

bool isEmpty_NoHead(LinkQueue &Q){
    return Q.front == NULL;
}

int main(){
    LinkQueue Q;
    initQueue_NoHead(Q);
    enQueue_NoHead(Q,41);
    int noX = deQueue_NoHead(Q);
    bool flag = isEmpty_NoHead(Q);
    printf("The No head dequeue element = %d\n",noX);
    printf("The queue isEmpty = %d\n",flag);
    //    initQueue_Head(Q);
//    printf("12");
//
//    enQueue_Head(Q,5);
//    enQueue_Head(Q,6);
//    enQueue_Head(Q,7);
//    enQueue_Head(Q,7);
//
//    int x = deQueue_Head(Q);
//    printf("The dequeue element = %d\n",x);
//    printf("The isEmpty = %d\n",isEmpty(Q));
}