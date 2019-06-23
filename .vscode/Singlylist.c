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

//p为原链表，elem表示新数据元素，add表示新元素要插入的下标
link* insertElem_withHead(link *p, int elem, int add){
    if (add < 0)
    {
        printf("删除位置异常");
        return p;
    }
    link *temp = NULL; //声明临时节点temp
    temp = p; //指向无内容的头指针
    for (int i = 0; i <= add - 1; i++) //找插入位置的前接元素
    {
        if (temp->next)
        {
            temp = temp->next;
        }
    }
    link *a = (link*)malloc(sizeof(link)); //声明一个新节点
    a->elem = elem;
    a->next = temp->next; //初始化新节点,并将其连接到链表上
    temp->next = a; //前方对接
    return p;
}

link* insertElem(link *p, int elem, int add){
    if (add < 0)
    {
        printf("删除位置异常");
        return p;
    }
    link *temp = NULL;
    temp = p;
    link *a = (link*)malloc(sizeof(link));
    a->elem = elem;
    if (add == 0)
    {
        a->next = p;
        return a;
    }else
    {
        for (int i = 1; i <= add - 1; i++)
        {
            if (temp->next)
            {
                temp = temp->next;
            }
            
        }
        a->next = temp->next;
        temp->next=a;
        return p;
    }   
}

//链表删除元素 del为下标
link* delElem(link *p, int del){
    if (del < 0)
    {
        printf("删除位置异常");
        return p;
    }
    link *temp = NULL;
    if (del == 0)
    {
        return p->next;
    }else
    {
        temp=p;
        for (int i = 1; i <= del-1; i++)
        {
            if (temp->next)
            {
                temp=temp->next;
            }
        }
        link *haha = temp->next;
        if (temp->next)
        {
            temp->next = temp->next->next;
            free(haha);
        }
        
        return p;
    }
}

link* delElem_withHead(link *p, int del){
    if (del < 0)
    {
        printf("删除位置异常");
        return p;
    }
    link *temp = NULL;
    temp = p;
    for (int i = 0; i <= del - 1; i++)
    {
        if (temp->next)
        {
            temp=temp->next;
        }

    }
    link *haha = temp->next;
    if (temp->next)
    {
        temp->next = temp->next->next;
        free(haha);
    }
    return p;
}

// 链表查找元素, elem为被查找元素, 返回下标
int selectElem(link *p, int elem){
    link *temp = NULL;
    temp = p;
    int i = 0;
    while (temp)
    {
        if (temp->elem == elem)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

int selectElem_withHead(link *p, int elem){
    link *temp = NULL;
    temp = p->next;
    int i = 0;
    while (temp)
    {
        if (temp->elem == elem)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

//链表更新元素 add表示更新的位置, newElem表示更新的值
link* amendElem_withHead(link *p, int add, int newElem){
    if (add < 0)
    {
        printf("下标异常");
        return p;
    }
    link *temp = NULL;
    temp = p;
    for (int i = 0; i <= add; i++)
    {
        temp = temp->next;
    }
    if (temp)
    {
        temp->elem = newElem;
    }else
    {
        printf("越界,没有修改");
    }
    return p;
}

link* amendElem(link *p, int add, int newElem){
    if (add < 0)
    {
        printf("下标异常");
        return p;
    }else if (add == 0)
    {
        p->elem = newElem;
        return p;
    }else{
        link *temp = NULL;
        temp = p;
        for (int i = 1; i <= add; i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            temp->elem = newElem;
        }else
        {
            printf("越界,没有修改");
        }
        return p;
    }
}

// 初始化并显示链表元素
// int main() {
//     //初始化链表（1，2，3，4）
//     printf("初始化链表为：\n");
//     link *p=initLink();
//     display(p);
//     return 0;
// }


int main() {
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p=initLink();
    display(p);
  
    printf("在第4的位置插入元素5：\n");
    p=insertElem(p, 5, 4);
    display(p);
  
    printf("删除第三位:\n");
    p=delElem(p, 3);
    display(p);
  
    printf("查找元素2的位置为：\n");
    int address=selectElem(p, 2);
    if (address==-1) {
        printf("没有该元素");
    }else{
        printf("元素2的位置为：%d\n",address);
    }
    printf("更改第3的位置上的数据为7:\n");
    p=amendElem(p, 3, 7);
    display(p);
  
    return 0;
}
