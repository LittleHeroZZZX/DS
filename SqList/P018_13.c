#include "SqList.h"
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

void findMissNum(SqList l, int *num)
{
    // 2018统考真题——寻找一个数组中缺失的最小正整数
    // 本题只要求时间复杂度最小

    // 用数组下标来标记元素是否出现过
    // O(n)+O(n)

    int *count = (int *)malloc(sizeof(int) * l.length);
    memset(count, 0, sizeof(int) * l.length);
    for (int i=0; i<l.length; i++)
    {
        if (l.data[i] > 0 && l.data[i] <= l.length)
            count[l.data[i]-1] = 1;
    }
    for (int i=0; i<l.length; i++)
    {
        if (count[i] == 0)
        {
            *num = i+1;
            return;
        }
    }
    *num = l.length+1;
    return;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {1, 2, 3, 4, 5, 7};
    SqList l1, l2;
    initSqList(&l1, arr1, 6);
    initSqList(&l2, arr2, 6);
    int num;
    findMissNum(l1, &num);
    printf("%d\n", num);
    findMissNum(l2, &num);
    printf("%d\n", num);
}
