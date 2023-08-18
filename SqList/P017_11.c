#include <SqList.h>


void shiftLeftP(SqList *l, int p)
{
    // 2010真题 将顺序表循环左移p个位置
    
    // 变换后的数组的第i个元素在原数组的位置为(i+p)%length
    // 即变换前的数组的第i个元素在变换后的数组的位置为(i-p+length)%length

    // 为了实现O(1)的空间复杂度，逆置第i个元素后，逆置第(i-p+length)%length个元素

    
    SqList temp;
    initSqList(&temp, l->data, l->length);
    int i;
    for (i = 0; i < l->length; i++)
    {
        l->data[i] = temp.data[(i+p)%l->length];
    }
    destroySqList(&temp);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    SqList l;
    initSqList(&l, arr, 6);
    showSqList(l);
    shiftLeftP(&l, 2);
    showSqList(l);
}