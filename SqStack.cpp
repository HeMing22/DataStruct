#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct Stack{
	int data[MaxSize];
	int top;
}Stack;

bool Init_Stack(Stack &S){
	S.top = -1;
	return true;
}

bool Stack_Empty(Stack &S){
	bool isEmpty = false;
	if(S.top == -1){
		isEmpty = true;
	}
	return isEmpty;
}

bool Push(Stack &S, int x){
	S.data[++S.top] = x;
	return true;
}

int Pop(Stack &S){
	if(Stack_Empty(S)){
		printf("The Stack is Empty");
		return -1;

	}

	return S.data[S.top--];
}

int GetTop(Stack &S, int &x){
	if(Stack_Empty(S)){
		printf("The Stack is Empty");
		return -1;
	}
	x = S.data[S.top];
	return x;
}

int main(){
	Stack S;
	
	Init_Stack(S);
	
	Push(S,10);
	Push(S,8);
	Push(S,5);

	int x = Pop(S);
	int x1 = Pop(S);
	int x2 = Pop(S);

	printf("The stack to = %d\n",x);
	printf("The stack to = %d\n",x1);
	printf("The stack to = %d\n",x2);

}

