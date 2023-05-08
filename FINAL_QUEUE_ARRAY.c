/* Menu Driven C Program to implement queue using array without STRUCTURE and HEAP[malloc] MEMORY*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue_arr[MAX];
int rear=-1;
int front=-1;

void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Insert\n");
                printf("2.Delete\n");
                printf("3.Display element at the front\n");
                printf("4.Display all elements of the queue\n");
                printf("5.Check if Queue is Empty\n");
                printf("6.Check if Queue is Full\n");
                printf("7.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nInput the element for adding in queue : ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                case 2:
                        item=del();
                        printf("\nDeleted element is  %d\n",item);
                        break;
                case 3:
                        printf("\nElement at the front is %d\n",peek());
                        break;
                case 4:
                        display();
                        break;
                case 5:
                    isEmpty() ;
                    if(isEmpty()) {
                        printf("The Queue is Empty\n") ;
                    }
                    else{
                        printf("The Queue is not Empty\n") ;
                    }
                    break; 
                case 6 :
                    isFull() ;
                       if(isFull()) {
                        printf("The Queue is Full\n") ;
                    }
                    else{
                        printf("The Queue is not Full\n") ;
                    }
                    break; 
                case 7:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }/*End of switch*/
        }/*End of while*/

        return 0;

}

void insert(int item)
{
        if( isFull() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if( front == -1 )
                front=0;
        rear=rear+1;
        queue_arr[rear]=item ;
}

int del()
{
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=queue_arr[front];
        front=front+1;
        return item;
}

int peek()
{
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
        }
        return queue_arr[front];
}

int isEmpty()
{
        if( front==-1 || front==rear+1 )
                return 1;
        else
                return 0;
}

int isFull()
{
        if( rear==MAX-1 )
                return 1;
        else
                return 0;
}/*End of isFull()*/

void display()
{
        int i;
        if ( isEmpty() )
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n\n");
        for(i=front;i<=rear;i++)
                printf("%d  ",queue_arr[i]);
        printf("\n\n");
}
