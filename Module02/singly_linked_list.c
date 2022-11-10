#include <stdio.h>
#include <stdlib.h>

// user defined data type
struct node
{
    int data;
    struct node *next;
};

// function to display the data of each node
void display(struct node **head)
{
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

// function to return a pointer to a memory address of above data type allocated dynamically
struct node *createNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to add a node in the begining of the linked list
void addStart(struct node **head, int val)
{
    if (*head == NULL)
        *head = createNode(val);
    else
    {
        struct node *temp = createNode(val);
        temp->next = *head;
        *head = temp;
    }
}

// function to add a node at the end of the linked list
void addEnd(struct node **head, int val)
{
    if (*head == NULL)
        *head = createNode(val);
    else
    {
        struct node *temp = createNode(val);
        struct node *runner = *head;
        while (runner->next != NULL)
            runner = runner->next;
        runner->next = temp;
    }
}

// function to insert a node before the given value
void addBet(struct node **head, int val, int place)
{
    if ((*head)->data == place)
        addStart(head, val);
    else
    {
        struct node *temp = createNode(val);
        struct node *runner = *head;
        while (runner->next->data != place)
            runner = runner->next;
        temp->next = runner->next;
        runner->next = temp;
    }
}

// deleting first node of the linked list.
void delStart(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    free(temp);
}

// deleting last node of the linked list.
void delEnd(struct node **head)
{
    struct node *temp = *head;
    struct node *dump = NULL;
    while (temp->next->next != NULL)
        temp = temp->next;
    dump = temp->next;
    temp->next = NULL;
    free(dump);
}

// deleting the node of the linked list which has value "place" stored.
void delBet(struct node **head, int place)
{
    if ((*head)->data == place)
        delStart(head);
    else
    {
        struct node *runner = *head;
        struct node *dump = NULL;
        while (runner->next->data != place)
            runner = runner->next;
        dump = runner->next;
        runner->next = runner->next->next;
        dump->next = NULL;
        free(dump);
    }
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
void search(struct node **head, int val)
{
    int pos = position(head, val);
    if (pos == -1)
        printf("%d is not in the list.\n", val);
    else
        printf("%d is in node %d.\n", val, pos);
}

// displaying the nodes in reverse order
void display_rev(struct node **head)
{
    struct node *temp = *head;
    struct node *sup = NULL;
    while (temp != sup && temp != NULL)
    {
        struct node *temp1 = *head;
        while (temp1->next != NULL && temp1->next != sup)
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
    struct node *head = NULL;
    // adding nodes in different positions as defined in the respective function above.
    addStart(&head, 89);
    addStart(&head, 1);
    addEnd(&head, 0);
    addEnd(&head, 150);
    addBet(&head, 111, 89);
    // displaying the values of the linked list
    display(&head);
    // searching for 0 in the list.
    search(&head, 0);
    // displaying the values of linked list in reverse order.
    display_rev(&head);
    // deleting the nodes in different positions as defined in the respective function above.
    delStart(&head);
    display(&head);
    delEnd(&head);
    display(&head);
    delBet(&head, 89);
    display(&head);
    return 0;
}