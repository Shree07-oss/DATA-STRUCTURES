#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int element)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = element;

        printf("Element inserted successfully\n");
    }
}
int dequeue()
{
    int element;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        element = queue[front];
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }

        return element;
    }
}
void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}
int main()
{
    int choice;
    int element;

    while (1)
    {
        printf("\n1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the element: ");
            scanf("%d", &element);

            enqueue(element);
        }
        else if (choice == 2)
        {
            element = dequeue();

            if (element != -1)
            {
                printf("Deleted element: %d\n", element);
            }
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
