#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

void initList(SqList &L){
    for(int i = 0;i<MaxSize;i++)
        L.data[i] = 0;
    L.length = 0;
}

bool ListInsert(SqList &L,int i,int elem){
    if(L.length >= MaxSize)
        return false;
    if(i<1 || i > L.length+1)
        return false;
    for(int j = L.length;j>=i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = elem;
    L.length ++;
    return true;
}

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
int main01(){
    SqList L;
    initList(L);
    ListInsert(L,1,5);
    ListInsert(L,1,6);
    printf("%d\n",L.data[0]);
    printf("%d",L.data[1]);

}
