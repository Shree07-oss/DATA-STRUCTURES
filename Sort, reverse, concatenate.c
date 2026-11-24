#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* createList()
{
    struct Node *head = NULL, *temp, *newNode;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}
void display(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
struct Node* reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void sortList(struct Node *head, int order)
{
    struct Node *temp, *current;
    int swap;

    for(temp = head; temp != NULL; temp = temp->next)
    {
        for(current = temp->next; current != NULL;
            current = current->next)
        {
            if((order == 1 && temp->data > current->data) ||
               (order == 2 && temp->data < current->data))
            {
                swap = temp->data;
                temp->data = current->data;
                current->data = swap;
            }
        }
    }
}
struct Node* concatenate(struct Node *head1,
                         struct Node *head2)
{
    struct Node *temp;

    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    temp = head1;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}
int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    int choice;
     printf("\n----- LINKED LIST OPERATIONS -----\n");
        printf("1. Create First Linked List\n");
        printf("2. Create Second Linked List\n");
        printf("3. Display First Linked List\n");
        printf("4. Display Second Linked List\n");
        printf("5. Sort First List in Ascending Order\n");
        printf("6. Sort First List in Descending Order\n");
        printf("7. Reverse First Linked List\n");
        printf("8. Concatenate Two Linked Lists\n");
        printf("9. Display Concatenated Linked List\n");
        printf("10. Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nCreate First Linked List\n");
                head1 = createList();
                break;
            case 2:
                printf("\nCreate Second Linked List\n");
                head2 = createList();
                break;
            case 3:
                printf("\nFirst Linked List:\n");
                display(head1);
                break;
            case 4:
                printf("\nSecond Linked List:\n");
                display(head2);
                break;
            case 5:
                sortList(head1, 1);
                printf("\nAscending Order:\n");
                display(head1);
                break;
            case 6:
                sortList(head1, 2);
                printf("\nDescending Order:\n");
                display(head1);
                break;
            case 7:
                head1 = reverseList(head1);
                printf("\nReversed First Linked List:\n");
                display(head1);
                break;
            case 8:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("\nLists Concatenated Successfully!\n");
                break;
            case 9:
                printf("\nConcatenated Linked List:\n");
                display(head1);
                break;
            case 10:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while(choice != 10);
    return 0;
}
