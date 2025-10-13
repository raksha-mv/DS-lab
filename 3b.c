#include <stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;

void insert(int value)
{
    if((front==0&&rear==MAX-1)||(front==(rear+1)%MAX))
    {
        printf("queue overflow!cannot insert %d\n",value);
    }
    else
    {
        if (front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%MAX;
        }
        queue[rear]=value;
        printf("%d inserted into the queue \n",value);
    }
}
void delete()
{
    if(front==-1)
    {
        printf("queue underflow!queue is empty \n");
    }
    else
    {
        printf("deleted element: %d\n",queue[front]);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
}

void display()
{
    if(front==-1)
    {
        printf("queue is empty \n");
    }
    else
    {
        printf("queue elements: ");
        int i= front;
        while(1)
        {
            printf("%d",queue[i]);
            if(i==rear)
                break;
            i=(i+1)%MAX;
        }
        printf("\n");
    }
}
int main()
{
    int choice,value;
    while(1)
    {
        printf("\n circular queue operation:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("enter value to insert:");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting program \n");
            return 0;
        default:
            printf("Invalid choice!please try again \n");
        }
    }
    return 0;
}
