#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *array;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = size;
    stack->array = (int *)calloc(stack->size, sizeof(int));
    return stack;
}

int isEmpty(Stack **stack)
{
    return (*stack)->top == -1;
}

int isFull(Stack **stack)
{
    return (*stack)->top == (*stack)->size;
}

void display(Stack **stack)
{
    int runner = (*stack)->top;
    for (int i = runner; i >= 0; i--)
        printf("%d ", (*stack)->array[i]);
    printf("\n");
}

void push(Stack **stack, int val)
{
    if (isFull(stack))
        printf("The stack is full.\n");
    else
    {
        (*stack)->array[++(*stack)->top] = val;
        printf("%d is pushed(added on top of the stack)\n", val);
    }
}

int pop(Stack **stack)
{
    if (isEmpty(stack))
        printf("The stack is empty.\n");
    else
    {
        printf("%d is poped(removed from top of the stack\n", (*stack)->array[(*stack)->top]);
        return (*stack)->array[(*stack)->top--];
    }
    return 0;
}

void peek(Stack *stack)
{

    printf("%d is on top of the stack.\n", stack->array[stack->top]);
}

int height(Stack *stack)
{
    return stack->top + 1;
}

int emptySpace(Stack *stack)
{
    return stack->size - height(stack);
}

int main()
{
    Stack *stack = createStack(10);
    push(&stack, 88);
    push(&stack, 8);
    push(&stack, 21);
    push(&stack, 34);
    push(&stack, 31);
    printf("Elements in the stack from top to buttom\n");
    display(&stack);
    pop(&stack);
    printf("Elements in the stack from top to buttom\n");
    display(&stack);
    peek(stack);
    printf("There are %d elements in the stack.\n", height(stack));
    printf("%d elements can still be stored in the stack.\n", emptySpace(stack));
    return 0;
}