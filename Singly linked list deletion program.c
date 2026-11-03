#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void createList(struct Node **head)
{
    struct Node *newNode,*temp;
    int n,i,value;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        if(newNode==NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for node %d: ",i);
        scanf("%d",&value);
        newNode->data=value;
        newNode->next=NULL;
        if(*head==NULL)
        {
            *head=newNode;
        }
        else
        {
            temp=*head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}
void deleteFromFirst(struct Node **head)
{
    struct Node *temp;
    if(*head==NULL)
    {
        printf("List is empty. Cannot Delete\n");
        return;
    }
    temp = *head;
    printf("%d is deleted at beginning\n",temp->data);
    *head=temp->next;
    free(temp);
}
void deleteFromEnd(struct Node **head)
{
    struct Node *temp;
    if(*head==NULL)
    {
        printf("List is empty. Cannot Delete\n");
        return;
    }
    temp=*head;
    if(temp->next==NULL)
    {
        printf("%d is deleted from end\n",temp->data);
        free(temp);
        *head=NULL;
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    printf("%d is deleted from end\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}
void deleteAtPosition(struct Node **head)
{
    struct Node *temp,*next;
    int i,position;
    if(*head==NULL)
    {
        printf("List is empty. Cannot Delete\n");
        return;
    }
    printf("Enter the position to delete: ");
    scanf("%d",&position);
    if(position<0)
    {
        printf("Invalid position\n");
        return;
    }
    temp=*head;
    if(position==0)
    {
        deleteFromFirst(head);
        return;
    }
    for(i=0;temp!=NULL&&i<position-1;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL||temp->next==NULL)
    {
        printf("Position out of range\n");
        return;
    }
    next = temp->next->next;
    printf("%d is deleted from position %d \n",temp->next->data,position);
    free(temp->next);
    temp->next=next;
}
void display(struct Node *head)
{
    struct Node *temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head=NULL;
    int choice;
    printf("\n----- SINGLY LINKED LIST -----");
    printf("\n1. Create Linked List");
    printf("\n2. Delete First Element");
    printf("\n3. Delete Specified Element");
    printf("\n4. Delete Last Element");
    printf("\n5. Display Linked List");
    printf("\n6. Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                createList(&head);
                break;
            case 2:
                deleteFromFirst(&head);
                break;
            case 3:
                deleteAtPosition(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program!...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
