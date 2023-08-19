#include "LinkList.h"
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Linklist initList()
{
    Linklist l = (Linklist) malloc(sizeof(LNode));
    l->data = 0;
    l->next = NULL;
    return l;
}

LNode *initNode(int data)
{
    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertDataByIndex(Linklist l, int data, int index)
{
    LNode* node = initNode(data);
    LNode* prev = l->next;
    while (index--)
    {
        if (prev == NULL)
            printf("index is invalid");
        prev = prev->next;
    }
    insertNodeByNode(prev, node);
    l->data++;
}

void insertNodeByIndex(Linklist l, LNode *node, int index)
{
    LNode* prev = l->next;
    while (index--)
    {
        if (prev == NULL)
            printf("index is invalid");
        prev = prev->next;
    }
    insertNodeByNode(prev, node);
    l->data++;
}

void insertDataByNode(LNode *prev, int data)
{
    // 调用后需要手动修改length
    LNode *node = initNode(data);
    insertNodeByNode(prev, node);
}

void insertNodeByNode(LNode *prev, LNode *node)
{
    // 调用后需要手动修改length
    prev->next = node;
}