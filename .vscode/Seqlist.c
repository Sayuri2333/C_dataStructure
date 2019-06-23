#include <stdio.h>
#include <stdlib.h>
#define Size 5 // 对size进行宏定义,初始化其值为5
// 自定义顺序表
typedef struct Table{
    int * head; //声明名为head的长度不确定的数组
    int length; //记录的当前存储元素的个数
    int size; //记录存储元素的上限
}table;
//初始化表的方法
table initTable(){
    table t; //声明一个新的表变量
    //malloc(size_t size)返回void*类型的指针,用于申请给定长度的内存空间,并返回内存空间头部的地址
    t.head=(int*)malloc(Size*sizeof(int)); // (int*)将void*型的指针转化为整型(int)指针
    if (!t.head) //申请失败
    {
        printf("初始化失败");
        exit(0); //直接退出
    }
    t.length=0; //初始化存储数据
    t.size=Size; //初始化数组容量
    return t;
}
//输出顺序表中元素
void displayTable(table t){
    for (int i=0;i<t.length;i++) {
        // printf("%d ", *(t.head+i));
        printf("%d ",t.head[i]); //t.head存储此内存空间的头部地址,即相当于数组变量名,因此可以使用下标访问
    }
    printf("\n");
}
//插入函数，其中，elem为插入的元素，add为插入到顺序表的位置(表示第几位,不是下标)
table addTable(table t,int elem,int add)
{
    //判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出）
    if (add>t.length+1||add<1) {
        printf("插入位置有问题");
        return t;
    }
    //做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
    if (t.length==t.size) {
        t.head=(int *)realloc(t.head, (t.size+1)*sizeof(int)); //realloc函数会在原有内存块基础上根据传入size的不同进行增减
        if (!t.head) {
            printf("存储分配失败");
            return t;
        }
        t.size+=1;
    } 
    //插入操作，需要将从插入位置开始的后续元素，逐个后移
    for (int i=t.length-1; i>=add-1; i--) {
        t.head[i+1]=t.head[i];
    }
    //后移完成后，直接将所需插入元素，添加到顺序表的相应位置
    t.head[add-1]=elem;
    //由于添加了元素，所以长度+1
    t.length++;
    return t;
}

// 顺序表删除元素
table delTable(table t, int add)
{
    if (add <1 || add > t.length)
    {
        printf("删除的位置有问题");
        return t;
    }
    for(int i = add-1; i <= t.length-1; i++){
        t.head[i] = t.head[i+1];
    }
    t.length--;
    return t;
}

//顺序查找函数，其中，elem表示要查找的数据元素的值, 返回下标
int selectTable(table t, int elem){
    if (t.length == 0)
    {
        return -1;
    }
    for (int i = 0; i < t.length; i++)
    {
        if (t.head[i] == elem)
        {
            return i;
        }
        
    }
    return -1;
}

//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
table amendTable(table t, int elem, int newElem){
    int i = selectTable(t, elem);
    if (i != -1)
    {
        t.head[i] = newElem;
    }
    return t;
}

//添加并输出元素
// int main(){
//     table t=initTable();
//     //向顺序表中添加元素
//     for (int i=1; i<=Size; i++) {
//         // *(t.head+i-1) = i;
//         t.head[i-1]=i; //通过下标获取内存并设置存储的整数
//         t.length++;
//     }
//     printf("顺序表中存储的元素分别是：\n");
//     displayTable(t);
//     return 0;
// }

int main(){
    table t1=initTable();
    for (int i=1; i<=Size; i++) {
        t1.head[i-1]=i;
        t1.length++;
    }
    printf("原顺序表：\n");
    displayTable(t1);
  
    printf("删除元素1:\n");
    t1=delTable(t1, 1);
    displayTable(t1);
  
    printf("在第2的位置插入元素5:\n");
    t1=addTable(t1, 5, 2);
    displayTable(t1);
  
    printf("查找元素3的位置:\n");
    int add=selectTable(t1, 3);
    printf("%d\n",add);
  
    printf("将元素3改为6:\n");
    t1=amendTable(t1, 3, 6);
    displayTable(t1);
    return 0;
}
