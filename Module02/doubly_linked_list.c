#include <stdio.h>
#include <stdlib.h>

// user defined datatype
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;

// function to display the data in the doubly linked list,
void display(Node **head)
{
    printf("Content of linked list\n");
    Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to count the number of nodes in the list
int countNode(Node **head)
{
    int count = 0;
    Node *temp = *head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// returning node number where "val" is stored
int position(struct node **head, int val)
{
    struct node *temp = *head;
    int pos = 1;

    while (temp->data != val && temp->next != NULL)
    {
        temp = temp->next;
        pos++;
    }
    if (temp->data == val)
        return pos;
    else
        return -1;
}

// searching for the "val"
void search(struct node **head)
{
    int val;
    printf("Search element: ");
    scanf("%d", &val);

    int pos = position(head, val);
    if (pos == -1)
        printf("%d is not in the list.\n", val);
    else
        printf("%d is in node %d.\n", val, pos);
}
Node *secLastNode(Node **head)
{
    Node *temp = *head;
    if (countNode(head) == 0)
    {
        printf("The list is empty.\n");
        return temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        return temp->prev;
    }
}
// displaying the nodes in reverse order
void display_rev(Node **head)
{
    Node *temp = secLastNode(head)->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// function to return a pointer to the memory address of above data type alocated dynamically.
Node *createNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to add a node in the begining of the doubly linked list.
void addStart(Node **head, int val)
{
    Node *temp = createNode(val);
    if (countNode(head) == 0)
        *head = temp;
    else
    {
        (*head)->prev = temp;
        temp->next = *head;
        *head = temp;
    }
}
// function to add a node at the end of the doubly linked list
void addEnd(Node **head, int val)
{
    Node *temp = createNode(head);
    Node *last = secLastNode(head);
    last = temp;
}

// function to add a node before the node having value "place".
void addBet(Node **head, int val, int place)
{
    if ((*head)->data == place)
        addStart(head, val);
    else
    {
        Node *runner = *head;
        while (runner->next->data != place)
            runner = runner->next;
        Node *temp = createNode(val);
        temp->next = runner->next;
        runner->next = temp;
        temp->prev = runner;
        temp->next->prev = temp;
    }
}

// function to delete the first node of the doubly linked list.
void delStart(Node **head)
{
    Node *dump = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    dump->next = NULL;
    free(dump);
}

// function to delete the last node of the doubly linked list.
void delEnd(Node **head)
{
    Node *dump = NULL;
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    dump = temp;
    temp->prev->next = NULL;
    dump->prev = NULL;
    free(dump);
}

// function to delete the node which has the value "place" stored.
void delBet(Node **head, int place)
{
    if ((*head)->data == place)
        delStart(head);
    else
    {
        Node *dump = NULL;
        Node *temp = *head;
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

// driving function
int main()
{
    // defining head in stack initialized with NULL value.
    Node *head = NULL;

    // adding nodes in differenet places with respect to the functions defined above.
    addEnd(&head, 16);
    addEnd(&head, 110);
    addStart(&head, 89);
    addStart(&head, 8);
    addBet(&head, 45, 89);
    // displaying the values stored in each node.
    display(&head);
    display_rev(&head);
    // searching for 110 in the list.
    // search(&head, 110);
    // displayng the values stored in each node in reverse order.
    // display_rev(&head);
    // deleting the nodes in different positions as defined in the respective function above.
    // delStart(&head);
    // display(&head);
    // delEnd(&head);
    // display(&head);
    // delBet(&head, 89);
    // display(&head);
    return 0;
}