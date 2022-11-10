#include <stdio.h>
#include <stdlib.h>
int SIZE = 10;
int HEIGHT = 0;

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct stack
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Node *createNode()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Element to push[%d]: ", HEIGHT + 1);
    scanf("%d", &temp->data);
    temp->next = NULL;
    HEIGHT++;
    return temp;
}

void deleteNode(Node **top)
{
    Node *temp = *top;
    *top = (*top)->next;
    printf("%d popped(removed from the top of the stack.\n", temp->data);
    free(temp);
    HEIGHT--;
}
void insertNode(Node **top)
{
    Node *temp = createNode();
    if (*top == NULL)
        *top = temp;
    else
    {
        temp->next = *top;
        *top = temp;
    }
}

int isEmpty(Stack *stack)
{
    return (stack->top == NULL);
}

int isFull(Stack *stack)
{
    return HEIGHT == SIZE;
}

void push(Stack *stack)
{
    if (isFull(stack))
        printf("The stack is full.\n");
    else
        insertNode(&(stack->top));
}

void display(Stack *stack)
{
    printf("The elements of the stack in top to buttom manner\n");
    Node *temp = stack->top;
    if (isEmpty(stack))
        printf("Stack is empty.\n");
    else
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    printf("\n");
}

void pop(Stack *stack)
{
    if (isEmpty(stack))
        printf("The stack is empty.\n");
    else
        deleteNode(&(stack->top));
}

int peek(Stack *stack)
{
    return stack->top->data;
}

int main()
{
    SIZE = 5;
    Stack *stack = createStack();
    push(stack);
    push(stack);
    push(stack);
    push(stack);
    push(stack);
    push(stack);
    display(stack);
    pop(stack);
    display(stack);
    printf("%d is on top of the stack.\n", peek(stack));
    printf("There are %d elements in the stack.\n", HEIGHT);
    printf("%d elements can still be added in the stack.\n", SIZE - HEIGHT);
    return 0;
}