typedef struct {
    int *data;
    int length;
} SqList;

void showSqList(SqList L);
void initSqList(SqList &L, int *arr, int length);