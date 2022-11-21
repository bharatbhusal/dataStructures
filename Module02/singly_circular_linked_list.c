#include <stdio.h>
#include <stdlib.h>

// user defined data type
typedef struct node
{
    int data;
    struct node *next;
} Node;

int countNode(Node **head)
{
    Node *temp = *head;
    int count = 0;
    if (temp == NULL)
        return count;
    else
        while (temp->next != *head)
        {
            count++;
            temp = temp->next;
        }
    return count + 1;
}

// function to return address of last node
Node *lastNode(Node **head)
{
    Node *runner = *head;
    if (countNode(head) != 0)
        while (runner->next != *head)
            runner = runner->next;
    return runner;
}

// function to display the data of each node
void display(Node **head)
{
    Node *temp = *head;
    if (lastNode(head) != NULL)
    {
        printf("Content of the Linked list:\n");
        while (temp->next != *head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
    else
        printf("The list is empty.\n");
}

// displaying the nodes in reverse order
void display_rev(Node **head)
{
    if (lastNode(head) != NULL)
    {
        printf("Content of the Linked list in reverse:\n");
        Node *temp = *head;
        Node *sup = NULL;
        int size = countNode(head);
        int array[size];
        for (int i = size - 1; i >= 0; i--, temp = temp->next)
            array[i] = temp->data;
        for (int i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
    else
        printf("The list is empty.\n");
}

// function to return a pointer to a memory address of above data type allocated dynamically
Node *createNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to add a node in the begining of the linked list
void addStart(Node **head, int val)
{
    printf("Adding a node in the begining of the list.\n");
    Node *temp = createNode(val);
    Node *last_node = lastNode(head);
    if (last_node != NULL)
    {
        temp->next = *head;
        *head = temp;
        last_node->next = *head;
    }
    else
    {
        *head = temp;
        temp->next = *head;
    }
}

// function to add a node at the end of the linked list
void addEnd(Node **head, int val)
{
    printf("Adding a node at the end of the list.\n");
    Node *temp = createNode(val);
    Node *last_node = lastNode(head);
    if (last_node == NULL)
    {
        *head = temp;
        temp->next = *head;
    }
    else
    {
        last_node->next = temp;
        temp->next = *head;
    }
}

// function to insert a node before the given value
void addBet(Node **head, int val, int place)
{
    Node *runner = *head;
    if (runner != NULL)
    {
        printf("Adding a node in middle of the list.\n");
        if (runner->data == place)
            addStart(head, val);
        else
        {
            Node *temp = createNode(val);
            while (runner->next->data != place && runner->next != *head)
                runner = runner->next;
            if (runner->next->data == place)
            {
                temp->next = runner->next;
                runner->next = temp;
            }
            else
                printf("%d does not exist in the list.\n", place);
        }
    }
    else
        printf("The list is empty.\n");
}

// deleting first node of the linked list.
void delStart(Node **head)
{
    Node *last_node = lastNode(head);
    if (last_node != NULL)
    {
        printf("Deleting first element in the list.\n");
        Node *temp = *head;
        if (countNode(head) == 1)
        {
            temp->next = NULL;
            *head = NULL;
            free(temp);
        }
        else
        {
            *head = (*head)->next;
            last_node->next = *head;
            temp->next = NULL;
            free(temp);
        }
    }
    else
        printf("The list is empty.\n");
}

// deleting last node of the linked list.
void delEnd(Node **head)
{
    if (lastNode(head) != NULL)
    {
        printf("Deleting last element in the list.\n");
        Node *temp = *head;
        Node *dump = NULL;
        while (temp->next->next != *head)
            temp = temp->next;
        dump = temp->next;
        temp->next = *head;
        dump->next = NULL;
        free(dump);
    }
    else
        printf("The list is empty.\n");
}

// deleting the node of the linked list which has value "place" stored.
void delBet(Node **head, int place)
{
    if (lastNode(head) != NULL)
    {
        printf("Deleting middle element in the list.\n");
        if ((*head)->data == place)
            delStart(head);
        else
        {
            Node *runner = *head;
            Node *dump = NULL;
            while (runner->next->data != place && runner->next != *head)
                runner = runner->next;
            if (runner->next->data == place)
            {
                if (runner->next->data == place && runner->next->next == *head)
                    printf("Deleting last element in the list.\n");
                dump = runner->next;
                runner->next = runner->next->next;
                dump->next = NULL;
                free(dump);
            }
            else
                printf("%d does not exist in the list.\n", place);
        }
    }
    else
        printf("The list is empty.\n");
}
// driving function
int main()
{
    // head of linked list in stack with NULL value
    Node *head = NULL;
    // adding nodes in different positions as defined in the respective function above.
    addEnd(&head, 0);
    addStart(&head, 89);
    addEnd(&head, 10);
    addStart(&head, 1);
    addEnd(&head, 150);
    display(&head);
    addBet(&head, 111, 150);
    // displaying the values of the linked list
    display(&head);
    // displaying the values of the linked list in reverse order
    display_rev(&head);
    // deleting the nodes in different positions as defined in the respective function above.
    delStart(&head);
    display(&head);
    delEnd(&head);
    display(&head);
    delBet(&head, 150);
    display(&head);
    return 0;
}