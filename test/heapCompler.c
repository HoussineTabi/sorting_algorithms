// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct myNode
{
    int d;
    struct myNode *next;
    struct myNode *prev;
} myList;
myList *insert_to_heap(myList *heap, int data)
{
    if (heap == NULL)
    {
        heap = malloc(sizeof(myList));
        if (!heap)
            return NULL;
        heap->d = data;
        heap->prev = NULL;
        heap->next = NULL;
        return heap; 
    }
    if (heap->d >= data)
        heap->prev = insert_to_heap(heap->prev, data);
    else
        heap->next = insert_to_heap(heap->next, data);
    return heap;
}
void printHeap(myList *heap, int n)
{
    if (heap == NULL)
        return;

    printHeap(heap->prev, n++);
    printHeap(heap->next, n++);
    printf("node%d = %d\n", n, heap->d);
}
int main() {
    // Write C code here
    myList *heap = NULL;
    int list[] = {5, 10, 11, 0, 1, 15, 9, 2};
    int size = sizeof(list) / sizeof(list[0]);
    int count = 0, max = list[0];
    int indexMax = 0;
    while (count < size)
    {
        if (list[count] >= max)
        {
            max = list[count];
            indexMax = count;
        }
        count++;
    }
    list[indexMax] = list[0];
    list[0] = max;
    count = 0;
    while (size > count)
        heap = insert_to_heap(heap, list[count++]);
    printHeap(heap, 1);
    printf("heap->d = %d\n", heap->d);
    printf("heap->prev->d = %d", heap->prev->d);
    
    return 0;
}
