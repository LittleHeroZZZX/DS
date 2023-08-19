#include "LinkList.h"
#include <stdio.h>

void reverseInPlace(Linklist l)
{
    // 链表的就地逆置
    // 思想是遍历链表，按照头插法插入链表头
    // 注意要把原来第一个节点的next在逆置后置null
    // O(n)+O(1)
    LNode *node = l->next;
    LNode *oldFirstNode = node;
    LNode *next = node;
    while (node)
    {
        next = node->next;
        insertNodeByNode(l, node);
        node = next;
    }
    oldFirstNode->next = NULL;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    Linklist list = initListByArray(arr, 6);
    showList(list);
    reverseInPlace(list);
    showList(list);
}

