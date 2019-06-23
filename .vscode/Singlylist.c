#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    char elem; //代表数据域
    struct Link *next; //代表指针域，指向直接后继元素
}link; //link为节点名，每个节点都是一个 link 结构体

//创建并初始化不具有头指针的链表
link * initLink(){
    link *p=NULL; //创建头指针
    link *temp = NULL; //创建链表尾部指针
    temp = (link*)malloc(sizeof(link)); //分配首元节点的内存并返回内存地址给尾部指针
    //首元节点(尾部节点)初始化
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//头指针指向首元节点
    for (int i=2; i<5; i++) {
        link *a=(link*)malloc(sizeof(link)); //分配内存地址给当前节点
        a->elem=i; //初始化当前节点值
        a->next=NULL; //初始化当前节点后继地址
        temp->next=a; //设置尾部节点后继指向当前节点
        temp=temp->next; //尾部元素后移
    }
    return p;
}

//创建并初始化具有头指针的链表
link* initLink_withHead(){
    link *head = NULL; //初始化头结点
    link *temp = NULL; //初始化尾部节点
    head = (link*)malloc(sizeof(link)); //分配头结点内存
    temp = head; //尾部节点指向头结点
    for (int i = 1; i < 5; i++) //同上
    {
        link *a = (link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return head;
}

void display(link *p){
    link *temp = NULL;
    temp = p;
    printf("当前链表元素如下: \n");
    while (temp)
    {
        printf("%d ", temp->elem);
        temp=temp->next;
    }
    printf("\n");
}

void display_withHead(link *p){
    link *temp = NULL;
    temp = p;
    printf("当前链表元素如下: \n");
    while (temp->next)
    {
        printf("%d ", temp->next->elem);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p=initLink();
    display(p);
    return 0;
}