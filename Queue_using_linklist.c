#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct Queue
{
    struct node* front;
    struct node* rear;
};

struct Queue* create_queue();
struct node* create_node();
void Enqueue(struct Queue*);
void Dequeue(struct Queue*);
void Display(struct Queue*);
void Get_front(struct Queue*);
void Get_rear(struct Queue*);

void main()
{
    int choice;
    struct Queue* queue = NULL;
    queue = create_queue();

    do
    {
    puts("****MENU****");
    puts("1 : Enqueue");
    puts("2 : Dequeue");
    puts("3 : Display");
    puts("4 : get front");
    puts("5 : get rear");
    
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
            case 4 : Get_front(queue);
                break;
            case 5 : Get_rear(queue);
                break;
        }
    }while(choice != 0);

puts("YOU HAVE SUCCESFULLY EXIT THE PROGRAM");
printf("\n");
}


struct Queue* create_queue()
{
    struct Queue* queue = NULL;

    queue = (struct Queue*) malloc(sizeof(struct Queue));
    if(queue == NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    queue ->front = NULL;
    queue ->rear = NULL;

    return queue;
}


struct node* create_node()
{
    struct node* p_newnode = NULL;
    int value;
    
    p_newnode = (struct node*) malloc(sizeof(struct node));
    if(p_newnode == NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    puts("Enter the value of element of Queue");
    scanf("%d",&value);

    p_newnode ->data = value;
    p_newnode ->next = NULL;

    return p_newnode;
}


void Enqueue(struct Queue* queue)
{
    struct node* newnode = NULL;

    newnode = create_node();

    if(queue ->front == NULL && queue ->rear == NULL)
    {
        queue ->front = newnode;
        queue ->rear = newnode;
    }

    queue ->rear ->next = newnode;
    queue ->rear = newnode;
}


void Dequeue(struct Queue* queue)
{
    if(queue ->front == NULL && queue ->rear == NULL)
    {
        puts("Queue is empty");
        return;
    }

    struct node* temp = queue ->front;

    queue ->front = queue ->front ->next;
    printf("Dequeue element id %d",temp ->data);

    free(temp);

    if(queue ->front == NULL)
    queue ->rear = NULL;
}

void Display(struct Queue* queue)
{
    struct node* trav_node = queue ->front;

    while(trav_node != NULL)
    {
        printf("[%d]->",trav_node ->data);
        trav_node = trav_node ->next;
    }
    printf("\n\n");
}

void Get_front(struct Queue* queue)
{
    printf("Front element of the Queue is [%d]",queue ->front ->data);
    printf("\n\n");
}

void Get_rear(struct Queue* queue)
{
    printf("Rear element of the Queue is [%d]",queue ->rear ->data);
    printf("\n\n");
}