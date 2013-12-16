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

int main(int argc, char** argv)
{
    int n = 10;
    List* list = createTestList(n);
    printList(list);
    return 0;
}

