#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top=NULL;
struct Node *front=NULL;
struct Node *rear=NULL;
void push()
{
    struct Node *newNode;
    int value;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d",&value);
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    printf("Element pushed successfully\n");
}
void pop()
{
    struct Node *temp;
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp=top;
    printf("Deleted element: %d\n", temp->data);
    top=top->next;
    free(temp);
}
void displayStack()
{
    struct Node *temp=top;
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void enqueue()
{
    struct Node *newNode;
    int value;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d",&value);
    newNode->data=value;
    newNode->next=NULL;
    if(front==NULL)
    {
        front=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
    printf("Element inserted successfully\n");
}
void dequeue()
{
    struct Node *temp;
    if(front==NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    temp=front;
    printf("Deleted element: %d\n", temp->data);
    front= front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    free(temp);
}
void displayQueue()
{
    struct Node *temp=front;
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice;
    printf("\n--- MAIN MENU ---\n");
    printf("1. Stack PUSH\n");
    printf("2. Stack POP\n");
    printf("3. Display Stack\n");
    printf("4. Queue ENQUEUE\n");
    printf("5. Queue DEQUEUE\n");
    printf("6. Display Queue\n");
    printf("7. Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                enqueue();
                break;
            case 5:
                dequeue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

