#include "SqList.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>


int calculateDistance(int n, int m, int p)
{
    return abs(n-m) + abs(m-p) + abs(p-n);
}

int stdFindNearestTuple(SqList l1, SqList l2, SqList l3, int *n, int *m, int *p)
{
    // 2020统考真题——寻找一个最短距离的三元组(n,m,p)
    // 三元组距离定义为|n-m|+|m-p|+|p-n|

    // 记录当前最小距离
    // 不断放大三元组中最小的那个(因为距离等于两倍最大值减去最小值)
    // O(n+m+p)

    int posN = 0, posM = 0, posP = 0;
    int dis = INT_MAX;
    while (1)
    {
        if (posN >= l1.length || posM >= l2.length || posP >= l3.length)
            break;
        int nowDis = calculateDistance(l1.data[posN], l2.data[posM], l3.data[posP]);
        if (nowDis < dis)
        {
            *n = l1.data[posN];
            *m = l2.data[posM];
            *p = l3.data[posP];
            dis = nowDis;
        }
        if (l1.data[posN] <= l2.data[posM] && l1.data[posN] <= l3.data[posP])
            posN++;
        else if (l2.data[posM] <= l1.data[posN] && l2.data[posM] <= l3.data[posP])
            posM++;
        else 
            posP++;
    }

    return dis;

    

}

int main()
{
    int arr1[] = {1, 2, 3, 4, };
    int arr2[] = {2, 3, 4, 5, 6};
    int arr3[] = {5, 7};
    SqList l1, l2, l3;
    initSqList(&l1, arr1, sizeof(arr1)/sizeof(int));
    initSqList(&l2, arr2, sizeof(arr2)/sizeof(int));
    initSqList(&l3, arr3, sizeof(arr3)/sizeof(int));
    int n, m, p;
    int dis = stdFindNearestTuple(l1, l2, l3, &n, &m, &p);
    printf("n=%d, m=%d, p=%d, dis=%d\n", n, m, p, dis);
    return 0;
}