#include "LinkList.h"
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

void deleteAbsSameNode(Linklist l, int m, int n)
{
    // 2015统考真题——删除绝对值相同的结点
    // 思路：对于空间复杂度没有约束，且链表的绝对值上限为n，则使用一个数组来记录每个绝对值出现的次数，然后遍历链表，删除绝对值出现次数大于1的结点
    // O(m)+O(n)

    int *nums = (int*)malloc(sizeof(int)*(n+1));
    memset(nums, 0, sizeof(int)*(n+1));
    LNode *node = l->next;
    while (node != NULL)
    {
        nums[abs(node->data)]++;
        node = node->next;
    }
    node = l;
    while (node->next != NULL)
    {
        if (nums[abs(node->next->data)] > 1)
        {
            LNode *temp = node->next;
            node->next = temp->next;
            free(temp);
            l->data--;
        }
        else
        {
            node = node->next;
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, -4, 5, 6, 7, 3, 4, 5, 6};
    Linklist l = initListByArray(a, 11);
    showList(l);
    deleteAbsSameNode(l, 11, 7);
    showList(l);
    return 0;
}