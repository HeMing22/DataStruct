#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

//定义栈
typedef struct Stack{
	int data[MaxSize];
	int top;
}Stack;

//初始化栈
bool Init_Stack(Stack &S){
	S.top = -1;
	return true;
}

//判断栈是否为空
bool Stack_Empty(Stack &S){
	return S.top == -1;
}

//入栈
bool Push(Stack &S, int x){
	S.data[++S.top] = x;
	return true;
}

//出栈
int Pop(Stack &S){
	if(Stack_Empty(S)){
		printf("The Stack is Empty");
		return -1;

	}
	return S.data[S.top--];
}

//获取栈顶元素，而不弹出栈
int GetTop(Stack &S){
	if(Stack_Empty(S)){
		printf("The Stack is Empty");
		return -1;
	}
	return  S.data[S.top];
}

//测试
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

