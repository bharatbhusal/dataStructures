// function to display the data in the doubly linked list,
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
