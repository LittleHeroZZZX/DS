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