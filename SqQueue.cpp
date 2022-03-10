#include<stdio.h>

#define MaxSize 10
typedef struct{
	int data[MaxSize];
	int rear,front;
}SqQueue;

void initQueue(SqQueue &Q){
	Q.rear = Q.front = 0;
}
void enQueue(SqQueue &Q,int val){
		Q.data[Q.rear] = val;
		Q.rear++;		
}

int deQueue(SqQueue &Q){
	int elem;
	elem = Q.data[Q.front];
	Q.front++;
	return elem;
}

bool isFull(SqQueue &Q){
	if(Q.rear == MaxSize)
		return true;
	return false;
}

bool isEmpty(SqQueue &Q){
	return Q.front == Q.rear;
}
int main(){
	SqQueue Q;
	initQueue(Q);
	enQueue(Q,1);
	enQueue(Q,2);
	enQueue(Q,3);
	enQueue(Q,4);
	enQueue(Q,5);
	enQueue(Q,6);
	enQueue(Q,7);
	enQueue(Q,8);
	enQueue(Q,9);


	// printf("the dequeue element = %d\n",x);
	// printf("the dequeue element = %d\n",x2);
	// printf("the dequeue element = %d\n",x3);
	printf("the queue isFull = %d\n",isFull(Q));

}