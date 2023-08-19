typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *Linklist;

Linklist initList();
LNode* initNode(int data);
Linklist initListByArray(int *data, int n);
void insertDataByIndex(Linklist l, int data, int index);
void insertNodeByIndex(Linklist l, LNode *node, int index);
void insertDataByNode(LNode *prev, int data);
void insertNodeByNode(LNode *prev, LNode *node);
void showList(Linklist l);