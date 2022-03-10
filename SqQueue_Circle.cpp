#include<stdio.h>

#define MaxSize 5

typedef struct{
	int data[10];
	int rear,front;
}SqQueue_Circle;


bool isEmpty(SqQueue_Circle &Q){
	return Q.rear == Q.front;
}

bool isFull(SqQueue_Circle &Q){
	/*
		循环队列判定为满,使用取模运算后的结果得到队尾指针实际位置
		当环形队列已满时，实际仍然保留一个空位用于判定队列是否为空，不能删除
	*/
	return (Q.rear+1)%MaxSize == Q.front;
}

void initQueue(SqQueue_Circle &Q){
	Q.rear = Q.front = 0;
}

void enQueue(SqQueue_Circle &Q,int val){
	if(isFull(Q)){
		printf("The queue is Full\n");
		return;
	}
	Q.data[Q.rear] = val;

	/*
		循环队列判定队列是否已满时不能使用 Q.rear == MaxSize;
		必须对队尾指针进行取模运算得到队尾指针的实际位置
	*/
	Q.rear = (Q.rear+1)%MaxSize;
}

int deQueue(SqQueue_Circle &Q){
	if(isEmpty(Q))
		return -1;
	int elem;
	elem = Q.data[Q.front];

	// 循环队列是队头指针循环移动
	Q.front = (Q.front+1)%MaxSize;
	return elem;
}


int main(){
	SqQueue_Circle Q;
	initQueue(Q);
	enQueue(Q,1);
	enQueue(Q,2);
	enQueue(Q,5);
	enQueue(Q,6);
	enQueue(Q,7);

	int x = deQueue(Q);
	int x2 = deQueue(Q);
	int x3 = deQueue(Q);
	int x4 = deQueue(Q);
	int x5 = deQueue(Q);
	printf("The deQueue element = %d\n",x);
	printf("The deQueue element = %d\n",x2);
	printf("The deQueue element = %d\n",x3);
	printf("The deQueue element = %d\n",x4);
	printf("The deQueue element = %d\n",x5);
	printf("The Queue is Null = %d\n",isEmpty(Q));
}