#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SqList;


//初始化线性表
void initList(SqList &L){
    for(int i = 0;i<MaxSize;i++)
        L.data[i] = 0;
    L.length = 0;
}

//在指定位置插入结点
bool ListInsert(SqList &L,int i,int elem){
    if(L.length >= MaxSize)
        return false;
    if(i<1 || i > L.length+1)
        return false;
    
    //将待插入结点后的元素后移一位
    
    for(int j = L.length;j>=i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = elem;
    L.length ++;
    return true;
}


//删除元素
bool ListDelete(SqList &L,int i,int &e){
    if(i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    for(int j = i; j<L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//测试
int main(){
    SqList L;
    initList(L);
    ListInsert(L,1,5);
    ListInsert(L,1,6);
    printf("%d\n",L.data[0]);
    printf("%d",L.data[1]);
}
