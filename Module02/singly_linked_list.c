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
    printf("Content of linked list\n");
    Node *temp = *head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
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

// displaying the nodes in reverse order
void display_rev(struct node **head)
{
    int size = countNode(head);
    int array[size];

    Node *temp = *head;
    for (int i = size - 1; i >= 0; i--)
    {
        array[i] = temp->data;
        temp = temp->next;
    }
}

// function to return a pointer to a memory address of above data type allocated dynamically
Node *createNode()
{
    int val;
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Value in the node: ");
    scanf("%d", &val);
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to add a node in the begining of the linked list
void addStart(Node **head)
{
    printf("Adding a node in the begining of the list.\n");
    Node *temp = createNode();
    if (countNode(head) == 0)
        *head = temp;
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

// function to add a node at the end of the linked list
void addEnd(Node **head)
{
    printf("Adding a node at the end of the list.\n");
    Node *temp = createNode();
    if (countNode(head) == 0)
        *head = temp;
    else
    {
        Node *runner = *head;
        while (runner->next != NULL)
            runner = runner->next;
        runner->next = temp;
    }
}

// function to insert a node before the given value
void addBet(Node **head)
{
    printf("Adding a node in middle of the list.\n");
    int place;
    printf("Before which node to add a node: ");
    scanf("%d", &place);
    Node *runner = *head;
    if (runner->data == place)
        addStart(head);
    else
    {
        Node *temp = createNode();
        while (runner->next != NULL && runner->next->data != place)
            runner = runner->next;
        if (runner->next != NULL && runner->next->data == place)
        {
            temp->next = runner->next;
            runner->next = temp;
        }
        else
            printf("%d does not exist in the list. So, node is not added.\n", place);
    }
}

// deleting first node of the linked list.
void delStart(Node **head)
{
    printf("Deleting first node.\n");
    if (countNode(head) == 0)
        printf("List is empty!\n");
    else
    {
        Node *dump = *head;
        *head = (*head)->next;
        dump->next = NULL;
        free(dump);
    }
}

// deleting last node of the linked list.
void delEnd(Node **head)
{
    printf("Deleting last node.\n");
    if (countNode(head) == 0)
        printf("List is empty!\n");
    else
    {
        Node *temp = *head;
        Node *dump = NULL;
        while (temp->next->next != NULL)
            temp = temp->next;
        dump = temp->next;
        temp->next = NULL;
        free(dump);
    }
}

// deleting the node of the linked list which has value "place" stored.
void delBet(Node **head)
{
    int place;
    printf("Deleting middle node\n");
    printf("To delete node(value): ");
    scanf("%d", &place);
    Node *runner = *head;
    if (runner->data == place)
        delStart(head);
    else
    {
        Node *dump = NULL;
        while (runner->next != NULL && runner->next->data != place)
            runner = runner->next;
        if (runner->next != NULL && runner->next->data == place)
        {
            dump = runner->next;
            runner->next = runner->next->next;
            dump->next = NULL;
            free(dump);
        }
        else
            printf("%d does not exist in the list.\n", place);
    }
}

// driving function
int main()
{
    // head of linked list in stack with NULL value
    Node *head = NULL;
    // adding nodes in different positions as defined in the respective function above.
    addStart(&head);
    addStart(&head);
    addEnd(&head);
    addEnd(&head);
    display(&head);
    addBet(&head);
    // displaying the values of the linked list
    display(&head);
    // displaying the values of linked list in reverse order.
    display_rev(&head);
    // searching for element in the list.
    search(&head);
    // deleting the nodes in different positions as defined in the respective function above.
    delStart(&head);
    display(&head);
    delEnd(&head);
    display(&head);
    delBet(&head);
    display(&head);
    return 0;
}