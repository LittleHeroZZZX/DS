#include "SqList.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>


int findMainNum(SqList l, int *mainNum)
{
    // 2013统考真题——寻找主元素

    // 统计各个元素出现次数 O(n)+O(n)
    int *count = (int *)malloc(sizeof(int) * l.length);
    memset(count, 0, sizeof(int) * l.length);
    for (int i=0; i<l.length; i++)
        count[l.data[i]]++;
    int maxPos = 0;
    for (int i=1; i<l.length; i++)
    {
        if (count[i] > count[maxPos])
            maxPos = i;
    }
    if (count[maxPos] > l.length/2)
    {
        *mainNum = l.data[maxPos];
        return 1;
    }
    else
    {
        *mainNum = -1;
        return 0;
    }
}

int stdFindMainNum(SqList l, int* mainNum)
{
    // 把备选主元素，若碰到与主元素不同的元素，则计数减一，若计数为0，则更换备选主元素
    // 真正的主元素最后一定会剩下来（因为主元素个数大于一半）
    // 再检验是否为主元素

    // O(n)+O(1)
    int candidate = l.data[0];
    int count = 1;
    for (int i=1; i<l.length; i++)
    {
        if (l.data[i] == candidate)
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                candidate = l.data[i];
                count = 1;
            }
        }
    }
    count = 0;
    for (int i=0; i<l.length; i++)
    {
        if (l.data[i] == candidate)
            count++;
    }
    if (count > l.length/2)
    {
        *mainNum = candidate;
        return 1;
    }
    else
    {
        *mainNum = -1;
        return 0;
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
    int arr2[] = {1, 6, 3, 4, 6, 6, 6, 6, 6};
    SqList l1, l2;
    initSqList(&l1, arr1, 9);
    initSqList(&l2, arr2, 9);
    int mainNum;
    if (findMainNum(l1, &mainNum))
        printf("Main number is %d.\n", mainNum);
    else
        printf("No main number.\n");
    if (findMainNum(l2, &mainNum))
        printf("Main number is %d.\n", mainNum);
    else
        printf("No main number.\n");
    if (stdFindMainNum(l1, &mainNum))
        printf("Main number is %d.\n", mainNum);
    else
        printf("No main number.\n");
    if (stdFindMainNum(l2, &mainNum))
        printf("Main number is %d.\n", mainNum);
    else
        printf("No main number.\n");

}