#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int rare;
    int *array;
} Queue;

void createQueue(Queue **queue, int size)
{
    (*queue) = (Queue *)malloc(sizeof(Queue));
    (*queue)->front = 0;
    (*queue)->rare = 0;
    (*queue)->size = size;
    (*queue)->array = (int *)calloc(size, sizeof(int));
}

void enqueue(Queue **queue, int val)
{
    printf("Adding an element(%d) in the queue.\n", val);
    if ((*queue)->rare < (*queue)->size)
        (*queue)->array[(*queue)->rare++] = val;
    else
        printf("Overflow.\n");
}

void dequeue(Queue **queue)
{
    printf("Deleting an element in the queue.\n");
    if ((*queue)->front <= (*queue)->rare)
        (*queue)->front++;
}
void display(Queue **queue)
{
    printf("Content of the queue: \n");
    int runner = (*queue)->front;
    if ((*queue)->rare >= (*queue)->front && (*queue)->rare != (*queue)->front)
        while (runner < (*queue)->rare)
            printf("%d ", (*queue)->array[runner++]);
    else
        printf("Queue is empty.");
    printf("\n");
}
int main()
{
    Queue *qHead = NULL;
    createQueue(&qHead, 10);
    enqueue(&qHead, 98);
    enqueue(&qHead, 9);
    enqueue(&qHead, 90);
    enqueue(&qHead, 21);
    display(&qHead);
    dequeue(&qHead);
    display(&qHead);
    enqueue(&qHead, 23);
    display(&qHead);

    return 0;
}