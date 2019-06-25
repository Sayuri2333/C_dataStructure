# include <stdio.h>
# include <stdlib.h>
// 使用循环链表解决约瑟夫环的问题
typedef struct node{
    int number;
    struct node* next;
}person;

//初始化循环链表
person* initLink(int n){
    person* head = (person*)malloc(sizeof(person)); //声明表头内存空间
    head->number = 1; //初始化表头
    head->next = NULL;
    person* cyclic = head; //初始化临时指针
    for (int i = 2; i <= n; i++)
    {
        person* body = (person*)malloc(sizeof(person)); //声明新节点的内存空间
        body->number = i; //初始化新节点
        body->next = NULL;
        cyclic->next = body; //使用临时指针连接当前链表尾部以及新节点
        cyclic = cyclic->next;
    }
    cyclic->next = head; //将链表尾部与头部连接起来
    return head; //返回链表头
}

//约瑟夫环问题 head表示链表头 k为从第几号人开始 m为每隔几个人抽一次
void findAndKill(person* head, int k, int m){
    person* tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    } //找到链表头部的上一个节点(也就是尾部节点)
    //使用tail节点紧跟p节点前面来辅助删除操作
    person* p = head;
    while (p->number != k)
    {
        tail = p;
        p = p->next;
    } //p节点指向开始的人
    while (p->next != p) //当p->next为p时说明链表中只有一个节点了,循环结束
    {
        for (int i = 1; i < m; i++) //进行m-1次循环,tail和p前进m-1个位置
        {
            tail = p;
            p = p->next;
        }
        tail->next = p->next; //此时p节点需要被删除,将tail节点的下个节点指向p->next
        printf("出列人的编号为%d\n", p->number);
        free(p);
        p = tail->next; //指向下一个节点(每次循环万都要步进一位,所以循环体执行m-1次)
    }
    printf("出列人的编号为:%d\n", p->number);
    free(p);
}

int main(){
    printf("输入圆桌上的人数n:");
    int n;
    // scanf("%d",&n);
    n = 7;
    person * head=initLink(n);
    printf("从第k人开始报数(k>1且k<%d)：",n);
    int k;
    // scanf("%d",&k);
    printf("数到m的人出列：");
    int m;
    // scanf("%d",&m);
    k = 1; m = 3;
    findAndKill(head, k, m);
    return 0;
}