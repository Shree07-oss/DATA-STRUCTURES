#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void insertBeginning(struct Node **head, int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void insertEnd(struct Node **head, int value)
{
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertMiddle(struct Node **head, int value, int position)
{
    struct Node *newNode, *temp;
    int i;
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1)
    {
        insertBeginning(head, value);
        return;
    }
    temp = *head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Contents of the singly linked list are:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void createList(struct Node **head)
{
    int n, i, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i =0; i < n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        insertEnd(head, value);
    }
}
int main()
{
    struct Node *head = NULL;
    int choice, value, position;
    printf("\n----- SINGLY LINKED LIST -----\n");
    printf("1. Create Linked List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at Specified Position\n");
    printf("4. Insert at End\n");
    printf("5. Display Linked List\n");
    printf("6. Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                createList(&head);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertMiddle(&head, value, position);
                break;
            case 4:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program!...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

