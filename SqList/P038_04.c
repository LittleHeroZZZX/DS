#include "LinkList.h"
#include <stdio.h>

void doReversePrint(LNode *node)
{
    if (node->next)
        doReversePrint(node->next);
    printf("%d ", node->data);

}

void reversePrint(Linklist l)
{
    // 逆序打印链表
    // 可以逆置链表后打印、可以借助栈来打印、也可以写一个递归
    // O(n)+O(n)
    doReversePrint(l->next);
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    Linklist list = initListByArray(arr, 6);
    showList(list);
    reversePrint(list);
}