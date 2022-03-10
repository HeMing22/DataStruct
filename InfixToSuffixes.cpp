//
// Created by lenovo on 2022/3/9 0009.
//

#include<stdio.h>
#include <cstring>

#define MaxSize 20

typedef struct Stack {
    char str[MaxSize];
    int top;
} Stack;

void init(Stack &s){
    s.top = -1;
}
void push(Stack &s,char val){
    s.str[++s.top] = val;
}
char pop(Stack &s){
    return s.str[s.top--];
}
char peek(Stack &s){
    return s.str[s.top];
}

bool isEmpty(Stack &s){
    return s.top == -1;
}

int judgePriority(char op) {
    int opNum = -1;
    switch (op) {
        case '+':
            opNum = 0;
            break;
        case '-':
            opNum = 0;
            break;
        case '*':
            opNum = 1;
            break;
        case '/':
            opNum = 1;
            break;
        case '(':
            opNum = 2;
            break;
        case ')':
            opNum = 2;
            break;
    }
    return opNum;
}

Stack infixToSuffix(char str[], int len) {
    Stack s1, s2;//s1 为临时运算符储栈， s2 为后缀表达式存储栈
    init(s1), init(s2);
    for (int i = 0; i < len; i++) {

        if (str[i] >= 'A' && str[i] <= 'Z') {
            push(s2,str[i]);

        }else if(str[i] == '('){
            push(s1,str[i]);

        }else if(str[i] == ')'){ //若当前元素为')' 依次弹出栈中运算符 直至栈空或栈顶元素为'('
            while(!isEmpty(s1) && peek(s2) != '('){
                push(s2,pop(s1));
            }
        }else{
            //比较 当前运算符 与 临时栈中存储的运算符的优先级
            int curOp = judgePriority(str[i]);
            int preOp = judgePriority( peek(s1));
            //若栈不为空，且栈顶运算符优先级大于当前运算符 依次弹出栈中运算符
            while(!isEmpty(s1) && preOp>=curOp){
                //若运算符栈中运算符等于 ’)' 弹出栈顶元素，中止
                if(peek(s1) == '('){
                    pop(s1);
                    break;
                }
                //将弹出的运算符，加入到后缀表达式栈中
                push(s2,pop(s1));
                preOp = judgePriority(peek(s1));
            }
            //比较结束后，将当前运算符入栈
            push(s1,str[i]);
        }
    }

    //将运算符栈中剩余元素入后缀表达式栈
    while(!isEmpty(s1)){
        push(s2,pop(s1));
    }
    return s2;
}

int main(){
    Stack s;
    char str[]={'A','+','B','*','(','C','-','D',')','-','E','/','F'}; // A B C D - * + E F / -
    char str2[]={'A','+','(','B','-','C',')'}; // A B C - +

    int len = sizeof(str)/sizeof(char);
    int len2 = sizeof(str2)/sizeof(char);

    printf("the str len = %d\nthe str2 len = %d\n",len,len2);

    s = infixToSuffix(str2,len2);

    for(int i = 0;i<len2;i++){
        printf("%2c",pop(s));
    }
}