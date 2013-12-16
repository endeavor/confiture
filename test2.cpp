#include <stdio.h>

struct List
{
    List* next;
    int data;
};

List* createTestList(int n)
{
    List* list = new List();
    list->data = 0;
    list->next = 0;
    List* head = list;
    for (int i = 1; i < n; i++) {
        List* next = new List();
        next->data = i;
        next->next = 0;
        list->next = next;
        list = next;
    }
    return head;
}

void printList(List* list)
{
    int i = 0;
    while (list) {
        printf("[%d] %d\n", i, list->data);
        list = list->next;
        i++;
    }
}

List* reverseList(List* list)
{
// Ln->Ln->Ln
// oL<-nL<-Ln
// 0) We have pn = list head
// NOTE: do not forget about first list->next = 0
// 1) Save next node nn = node->next
// 2) Assign node->next = pn
// 3) Save previous node pn = node
// 4) Go to next node = nn

    List* pn = list;
    if (!list)
        return list;
    List* node = list->next;
    list->next = 0;
    while(node) {
        List* nn = node->next;
        node->next = pn;
        pn = node;
        if (nn)
            node = nn;
        else
            return node;
    }
    return list;
}

int main(int argc, char** argv)
{
    int n = 10;
    List* list = createTestList(n);
    list = reverseList(list);
    printList(list);
    return 0;
}
