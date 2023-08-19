#include "LinkList.h"
#include "stdio.h"


int getLastKElement(Linklist l, int k)
{
    // 2009统考真题——获取倒数第k个元素
    // 思路：设置两个指针，一个指针先走k步，然后两个指针同时走，当先走的指针到达尾部时，后走的指针就是倒数第k个元素
    // O(n)+O(1)
    LNode *p=l, *q=l;
    while (k--)
    {
        if (p->next == NULL)
        {
            return -1;
        }
        p = p->next;
    }
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    return q->next->data;  
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Linklist l = initListByArray(a, 5);
    showList(l);
    printf("%d\n", getLastKElement(l, 5));
    printf("%d\n", getLastKElement(l, 6));
    return 0;
}