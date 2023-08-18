#include "SqList.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>


void showSqList(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

void initSqList(SqList *L, int *arr, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        L->data[i] = arr[i];
    }
    L->length = length;
}

void inverseSqList(SqList *L, int start, int end)
{
    if (start < 0 || end > L->length - 1 || start >= end)
    {
        printf("Invalid start or end.\n");
        return;
    }
    int temp;
    for (int i=0; i<(end-start+1)/2; i++)
    {
        temp = L->data[start+i];
        L->data[start+i] = L->data[end-i];
        L->data[end-i] = temp;
    }
}
