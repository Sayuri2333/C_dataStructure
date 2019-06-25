# include <stdio.h>
# include <stdlib.h>
typedef struct line{
    struct line * prior; //指向直接前趋
    int data;
    struct line * next; //指向直接后继
}line;

line* initLine(line* head){
    head = (line*)malloc(sizeof(line)); //给连链表头部分配空间
    head->prior = NULL;
    head->next = NULL;
    head->data = 1; // 初始化链表头部内容
    line *list = head; // 初始化临时指针
    for (int i = 2; i <= 3; i++)
    {
        line *body = (line*)malloc(sizeof(line)); // 给新建节点分配空间

        body->prior = NULL;
        body->next = NULL;
        body->data = i; //初始化新建节点

        list->next = body;
        body->prior = list; // 链接新建节点与临时指针指向的节点
        list = list->next; //临时指针位置变换
    }
    return head;
}

void display(line* head){
    line* temp = head;
    while (temp)
    {
        if (temp->next == NULL)
        {
            printf("%d\n", temp->data);
        }else
        {
            printf("%d<->", temp->data);
        }
        temp = temp->next;
    }
    
}

// 初始化并展示双向链表
// int main(){
//     line *head = NULL;
//     head = initLine(head);
//     display(head);
//     return 0;
// }

line* insertLine(line* head, int data, int add){
    line *temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    if (head == NULL)
    {
        return temp;
    }
    if (add == 0)
    {
        temp->next = head;
        head->prior = temp;
        return temp;
    }else
    {
        line* insert = head;
        for (int i = 1; i < add; i++)
        {
            if (insert->next != NULL)
            {
                insert = insert->next;
            }
        }
        if (insert->next == NULL)
        {
            insert->next = temp;
            temp->prior = insert;
            return head;
        }else
        {
            insert->next->prior = temp;
            temp->next = insert->next->prior;
            temp->prior = insert;
            insert->next = temp;
            return head;
        }
    }
}

line* delLine(line* head, int data){
    line* temp = NULL;
    temp = head;
    while (temp)
    {
        if (temp->data != data)
        {
            temp = temp->next;
        }else
        {
            break;
        }
        
    }

    if (temp->next == NULL || temp->data != data)
    {
        printf("没找到数据\n");
        return head;
    }else if (temp->next == NULL)
    {
        temp->prior->next = NULL;
        free(temp);
    }else if (temp == head)
    {
        head = head->next;
        free(temp);
    }else
    {
        temp->prior->next = temp->next;
        temp->next->prior = temp->prior;
        free(temp);
    }
    return head;
}

int selectElem(line* head, int elem){
    line* temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == elem)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    printf("没找到\n");
    return -1;
}

line* amendElem(line* p, int add, int newElem){
    line* temp = p;
    if (add == 0)
    {
        temp->data = newElem;
        return temp;
    }
    for (int i = 1; i <= add; i++)
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    temp->data = newElem;
    return p;
}


int main() {
    line * head=NULL;
    //创建双链表
    head=initLine(head);
    display(head);
    //在表中第 3 的位置插入元素 7
    head=insertLine(head, 7, 3);
    display(head);
    //表中删除元素 2
    head=delLine(head, 2);
    display(head);

    printf("元素 3 的位置是：%d\n",selectElem(head,3));
    //表中第 3 个节点中的数据改为存储 6
    head = amendElem(head,3,6);
    display(head);
    return 0;
}