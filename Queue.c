#include<stdio.h>
#include<stdlib.h>

struct Queue                            //Creating a structure i.e to create user defined data type .
{
    int front;
    int rear;
    int capacity;
    int* arr;
};

struct Queue* create_queue();           //Declaration of functions
void Enqueue(struct Queue*);
void Dequeue(struct Queue*);
int is_empty(struct Queue* queue);
int is_full(struct Queue* queue);
void Display(struct Queue* queue);
void get_rear(struct Queue* queue);
void get_front(struct Queue* queue);

void main()
{
    int choice;
    struct Queue* queue = NULL;        //Creating a pointer which will point user defined datatype variable.

    queue = create_queue();            //Calling create_queue function to create queue.

    do
    {
        puts("****MENU****");
        puts("1 : Enqueu");
        puts("2 : Dequeue");
        puts("3 : Display");
        puts("4 : Get front");
        puts("5 : get rear");
        puts("0 : Exit");

        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : Enqueue(queue);
                break;
            case 2 : Dequeue(queue);
                break;
            case 3 : Display(queue);
                break;
            case 4 : get_front(queue);
                break;
            case 5 : get_rear(queue);
                break;
        }
    } while (choice != 0);

    puts("You have succesfully exit the program ");
}

struct Queue* create_queue()
{
    struct Queue* queue = NULL;
    int capacity;

    queue = (struct Queue*)malloc(sizeof(struct Queue));

    if(queue == NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    puts("Enter the capacity of Queue");
    scanf("%d",&capacity);
    queue ->capacity = capacity;

    queue ->arr = (int*) malloc(queue ->capacity * sizeof(int));
    if(queue->arr == NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    queue ->front = -1;
    queue ->rear = -1;

    return queue;
}

int is_full(struct Queue* queue)
{
    return queue->rear == (queue ->capacity) -1;
}

int is_empty(struct Queue* queue)
{
    return queue ->front == queue ->rear;
}

void Enqueue(struct Queue* queue)
{
    if(is_full(queue))
    {
        puts("Queue is full");
        printf("\n");
        return;
    }

    int element;
    puts("Enter your element");
    scanf("%d",&element);

    (queue ->rear)++;
    queue ->arr[queue ->rear] = element;
}

void Dequeue(struct Queue* queue)
{
    if(is_empty(queue))
    {
        puts("Queue is empty");
        printf("\n");
        return;
    }


    (queue ->front)++;
    printf("Dequeue element is %d",queue ->arr[queue ->front]);
    
    printf("\n\n");
}

void Display(struct Queue* queue)
{
    if(is_empty(queue))
    {
        puts("Queue is empty");
        printf("\n");
        return;
    }
    int i;

    puts("Queue contains following elements:-");

    for(i = (queue ->front)+1 ; i <= queue ->rear ; i++)
    {
        printf("[%d]->",queue->arr[i]);
    }
    printf("\n\n");
}

void get_front(struct Queue* queue)
{
    printf("Queue's Front Element is %d",queue ->arr[(queue->front)+1]);
    printf("\n\n");
}

void get_rear(struct Queue* queue)
{
    printf("Queue's Rear element is %d",queue ->arr[queue ->rear]);
    printf("\n\n");
}