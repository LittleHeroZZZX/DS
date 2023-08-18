#include <stdio.h>
#include "SqList.h"

void swapSequence(SqList *L, int i, int j)
{
    // 交换顺序表中前i个元素和后j个元素的位置

    // 逆置前i个元素、逆置后j个元素，再逆置整个顺序表
    inverseSqList(L, 0, i-1);
    inverseSqList(L, i, i+j-1);
    inverseSqList(L, 0, i+j-1);

}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    SqList l;
    initSqList(&l, arr, 6);
    showSqList(l);
    swapSequence(&l, 2, 4);
    showSqList(l);


}