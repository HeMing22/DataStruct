#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct LinkStack{
    int data;
    struct LinkStack *next;
}LinkStack;

LinkStack* InitStack(LinkStack *S){
	S = NULL;
	return S;
}

bool StackEmpty(LinkStack *S){
	return S == NULL;
}

LinkStack* Push(LinkStack *S,int x){
	LinkStack *node = (LinkStack*)malloc(sizeof(LinkStack));
	node->data = x;
	node->next = S;
	S = node;
	return S;
}

LinkStack* Pop(LinkStack *S,int *x){
	LinkStack *p = S;
	*x = S->data;
	S = p->next;
	free(p);
	return S;
}

int main(){
	LinkStack *S = NULL;
	S = InitStack(S);
	S =  Push(S,10);
	S =  Push(S,8);
	S =  Push(S,5);

	int x,x1,x2;
	S = Pop(S,&x);
	S = Pop(S,&x1);
	S = Pop(S,&x2);
	bool flag = StackEmpty(S);

	printf("The Stack top element = %d\n",x);
	printf("The Stack top element = %d\n",x1);
	printf("The Stack top element = %d\n",x2);
	printf("The stack is empty = %d\n",flag);
}

