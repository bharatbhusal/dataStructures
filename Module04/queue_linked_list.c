#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rare;
} Queue;

Node *createNode(int val)
{

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void createQueue(Queue **queue)
{
    *queue = (Queue *)malloc(sizeof(Queue));
    (*queue)->front = NULL;
    (*queue)->rare = (*queue)->front;
}

void enqueue(Queue **queue, int val)
{
    printf("Adding an element(%d) in the queue.\n", val);
    Node *node = createNode(val);
    if ((*queue)->front == NULL)
    {
        (*queue)->front = node;
        (*queue)->rare = node;
    }
    else
        (*queue)->rare->next = node;
    (*queue)->rare = node;
}

void dequeue(Queue **queue)
{
    printf("Deleting an elementin the queue.\n");
    if ((*queue)->front != NULL)
    {
        Node *dump = (*queue)->front;
        (*queue)->front = (*queue)->front->next;
        dump->next = NULL;
        free(dump);
    }
}

void display(Queue **queue)
{
    printf("Content of the Queue:\n");
    if ((*queue)->front != NULL)
    {
        Node *temp = (*queue)->front;
        while (temp != (*queue)->rare)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d \n", temp->data);
    }
}

int main()
{
    Queue *queue = NULL;
    createQueue(&queue);
    enqueue(&queue, 55);
    enqueue(&queue, 52);
    enqueue(&queue, 2);
    enqueue(&queue, 20);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    return 0;
}