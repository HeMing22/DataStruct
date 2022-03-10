#include<stdio.h>
#include<stdlib.h>

//定义队列结点
typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

//定义队列
typedef struct LinkQueue{
    QNode *front,*rear;
} LinkQueue;

//初始化队列，开辟头节点
void initQueue_Head(LinkQueue &Q){
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    Q.front->next = NULL;
}

//入队
void enQueue_Head(LinkQueue &Q,int val){
    QNode *node = (QNode*)malloc(sizeof(QNode));
    node->data = val;
    node->next = NULL;
    Q.rear->next = node;
    Q.rear = node;
}

//出队
int deQueue_Head(LinkQueue &Q){
    int elem;
    QNode *p = Q.front->next;
    elem = p->data;
    Q.front->next = p->next;

    // 当尾指针等于头指针指向的下一个结点时，说明队列为空，此时应让头指针等于尾指针，然后删除出队元素，回归初始态
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return elem;
}

//判断队空
bool isEmpty(LinkQueue &Q){
    return Q.rear == Q.front;
}

//初始化无头结点队列
void initQueue_NoHead(LinkQueue &Q){
    Q.rear = NULL;
    Q.front = NULL;
}

//入队
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

//出队
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

//判空，这里和有头节点判空比较
bool isEmpty_NoHead(LinkQueue &Q){
    return Q.front == NULL;
}

//测试
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
