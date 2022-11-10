#include <stdio.h>
#include <stdlib.h>

// user defined data type
typedef struct node
{
    int data;
    struct node *next;
} Node;

// function to display the data of each node
void display(Node **head)
{
    Node *temp = *head;
    while (temp->next != *head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

// function to return a pointer to a memory address of above data type allocated dynamically
Node *createNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

Node *lastNode(Node **head)
{
    Node *runner = *head;
    while (runner->next != *head)
        runner = runner->next;
    return runner;
}
// function to add a node in the begining of the linked list
void addStart(Node **head, int val)
{
    if (*head == NULL)
    {
        *head = createNode(val);
        (*head)->next = *head;
    }
    else
    {
        Node *last_node = lastNode(head);
        Node *temp = createNode(val);
        temp->next = *head;
        *head = temp;
        last_node->next = *head;
    }
}

// function to add a node at the end of the linked list
void addEnd(Node **head, int val)
{
    if (*head == NULL)
    {
        *head = createNode(val);
        (*head)->next = *head;
    }
    else
    {
        Node *last_node = lastNode(head);
        Node *temp = createNode(val);
        temp->next = *head;
        last_node->next = temp;
    }
}

// function to insert a node before the given value
void addBet(Node **head, int val, int place)
{
    if ((*head)->data == place)
        addStart(head, val);
    else
    {
        Node *temp = createNode(val);
        Node *runner = *head;
        while (runner->next->data != place)
            runner = runner->next;
        temp->next = runner->next;
        runner->next = temp;
    }
}

// deleting first node of the linked list.
void delStart(Node **head)
{
    Node *last_node = lastNode(head);
    Node *temp = *head;
    *head = (*head)->next;
    last_node->next = *head;
    temp->next = NULL;
    free(temp);
}

// deleting last node of the linked list.
void delEnd(Node **head)
{
    Node *temp = *head;
    Node *dump = NULL;
    while (temp->next->next != *head)
        temp = temp->next;
    dump = temp->next;
    temp->next = *head;
    dump->next = NULL;
    free(dump);
}

// deleting the node of the linked list which has value "place" stored.
void delBet(Node **head, int place)
{
    if ((*head)->data == place)
        delStart(head);
    else
    {
        Node *runner = *head;
        Node *dump = NULL;
        while (runner->next->data != place)
            runner = runner->next;
        dump = runner->next;
        runner->next = runner->next->next;
        dump->next = NULL;
        free(dump);
    }
}

// displaying the nodes in reverse order
void display_rev(Node **head)
{
    Node *temp = *head;
    Node *sup = NULL;
    while (temp != sup && temp != NULL)
    {
        Node *temp1 = *head;
        while (temp1->next != *head && temp1->next != sup)
        {
            temp1 = temp1->next;
        }
        printf("%d ", temp1->data);
        sup = temp1;
        temp = temp->next;
    }
    printf("\n");
}
// driving function
int main()
{
    // head of linked list in stack with NULL value
    Node *head = NULL;
    // adding nodes in different positions as defined in the respective function above.
    addStart(&head, 89);
    addStart(&head, 1);
    addEnd(&head, 0);
    addEnd(&head, 150);
    addBet(&head, 111, 89);
    // displaying the values of the linked list
    display(&head);
    // displaying the values of the linked list in reverse order
    // display_rev(&head);
    // deleting the nodes in different positions as defined in the respective function above.
    delStart(&head);
    display(&head);
    delEnd(&head);
    display(&head);
    delBet(&head, 89);
    display(&head);
    return 0;
}