#include <stdio.h>
#include <stdlib.h>

// user defined datatype
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

// function to display the data in the linked list,
void display(struct node **head)
{
    struct node *temp = *head;
    while (temp->next != *head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

// function to return a pointer to the memory address of above data type alocated dynamically.
struct node *createNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to add a node in the begining of the linked list.
void addStart(struct node **head, int val)
{
    if (*head == NULL)
    {
        *head = createNode(val);
        (*head)->prev = *head;
        (*head)->next = *head;
    }
    else
    {
        struct node *temp = createNode(val);
        struct node *last_node = (*head)->prev;
        temp->next = *head;
        temp->prev = last_node;
        *head = temp;
        last_node->next = temp;
    }
}

// function to add a node at the end of the linked list
void addEnd(struct node **head, int val)
{
    if (*head == NULL)
    {
        *head = createNode(val);
        (*head)->prev = *head;
        (*head)->next = *head;
    }
    else
    {
        struct node *temp = createNode(val);
        struct node *last_node = (*head)->prev;
        temp->next = *head;
        temp->prev = last_node;
        last_node->next = temp;
        (*head)->prev = temp;
    }
}

// function to add a node before the node having value "place".
void addBet(struct node **head, int val, int place)
{
    if ((*head)->data == place)
        addStart(head, val);
    else
    {
        struct node *runner = *head;
        while (runner->next->data != place)
            runner = runner->next;
        struct node *temp = createNode(val);
        temp->next = runner->next;
        runner->next = temp;
        temp->prev = runner;
        temp->next->prev = temp;
    }
}

// function to delete the first node of the linked list.
void delStart(struct node **head)
{
    struct node *dump = *head;
    struct node *last_node = (*head)->prev;
    last_node->next = (*head)->next;
    *head = (*head)->next;
    (*head)->prev = last_node;
    dump->next = NULL;
    dump->prev = NULL;
    free(dump);
}

// function to delete the last node of the linked list.
void delEnd(struct node **head)
{
    struct node *last_node = (*head)->prev;
    struct node *dump = last_node;
    last_node->prev->next = *head;
    (*head)->prev = last_node->prev;
    dump->prev = NULL;
    dump->next = NULL;
    free(dump);
}

// function to delete the node which has the value "place" stored.
void delBet(struct node **head, int place)
{
    if ((*head)->data == place)
        delStart(head);
    else
    {
        struct node *dump = NULL;
        struct node *temp = *head;
        while (temp->data != place)
            temp = temp->next;
        dump = temp;
        temp->prev->next = temp->next;
        temp->prev->next->prev = temp->prev;
        dump->prev = NULL;
        dump->next = NULL;
        free(dump);
    }
}

// displaying the nodes in reverse order
void display_rev(struct node **head)
{
    struct node *temp = *head;
    while (temp->prev != *head)
    {
        printf("%d ", temp->prev->data);
        temp = temp->prev;
    }
    printf("%d ", temp->prev->data);
    printf("\n");
}

// driving function
int main()
{
    // defining head in stack initialized with NULL value.
    struct node *head = NULL;
    // adding nodes in differenet places with respect to the functions defined above.
    addStart(&head, 89);
    addStart(&head, 8);
    addEnd(&head, 110);
    addEnd(&head, 16);
    addBet(&head, 45, 89);
    // displaying the values of linked list in reverse order.
    display_rev(&head);
    // deleting the nodes in different positions as defined in the respective function above.
    display(&head);
    delStart(&head);
    display(&head);
    delEnd(&head);
    display(&head);
    delBet(&head, 89);
    display(&head);
    return 0;
}