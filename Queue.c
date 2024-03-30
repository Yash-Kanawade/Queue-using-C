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
int is_empty(struct Queue*);
int is_full(struct Queue*);
void Display(struct Queue*);
void get_rear(struct Queue*);
void get_front(struct Queue*);
void sorting(struct Queue*);

void main()
{
    int choice;
    struct Queue* queue = NULL;        //Creating a pointer which will point user defined datatype variable.

    queue = create_queue();            //Calling create_queue function to create queue.

    do                                 //Giving menu which contains various option of operation which can be perform on Queue.
    {                                              
        puts("****MENU****");
        puts("1 : Enqueu");
        puts("2 : Dequeue");
        puts("3 : Display");
        puts("4 : Get front");
        puts("5 : get rear");
        puts("0 : Exit");

        puts("Enter your choice");
        scanf("%d",&choice);            //Taking user's choice.

        switch(choice)                  //Using switch case according to user's choice.
        {
            case 1 : Enqueue(queue);    //Fuction of particular operation which all having common argument pass.
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
    struct Queue* queue = NULL;          //Creating the pointer for struct Queue.
    int capacity;

    queue = (struct Queue*)malloc(sizeof(struct Queue));
                                        //Getting memory for the queue in heap.
    if(queue == NULL)                   //Checking if memory has been allocated in heap or not. 
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    puts("Enter the capacity of Queue");
    scanf("%d",&capacity);              //Entering the capacity of Queue.
    queue ->capacity = capacity;

    queue ->arr = (int*) malloc(queue ->capacity * sizeof(int));
    if(queue->arr == NULL)              //Getting and checking allocation of memory for array in heap.
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    queue ->front = -1;
    queue ->rear = -1;

    return queue;
}

int is_full(struct Queue* queue)        //Checking if the Queue is full or not.
{
    return queue->rear == (queue ->capacity) -1;
}

int is_empty(struct Queue* queue)       //checking if the Queue is empty or not
{
    return queue ->front == queue ->rear;
}

void Enqueue(struct Queue* queue)       //defination of Enqueue function
{
    if(is_full(queue))                  //checking Queue is full or not to add new element
    {
        puts("Queue is full");
        printf("\n");
        return;
    }

    int element;                        //Getting the value of element 
    puts("Enter your element");
    scanf("%d",&element);

    (queue ->rear)++;
    queue ->arr[queue ->rear] = element;
}

void Dequeue(struct Queue* queue)       //defination of Dequeue function.
{
    if(is_empty(queue))                 //checking Queue is empty or not to delete an element.
    {
        puts("Queue is empty");
        printf("\n");
        return;
    }

    (queue ->front)++;
    printf("Dequeue element is %d",queue ->arr[queue ->front]);
    
    sorting(queue);                     //Sortiong function is use to sort the remainging elements in the Queue.

    free(&queue ->arr[queue ->rear]);   //Freeing the space of deleted element.
    free(&queue ->arr[queue ->front]);  //Freeing the space at rear position after sorting of queue.
    queue ->rear --;
    queue ->front --;

    printf("\n\n");
}

void Display(struct Queue* queue)       //Defination of Display function.
{
    if(is_empty(queue))                 //checking Queue is empty or not to Display the Queue.
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

void get_front(struct Queue* queue)     //Defination of get front function, in this value of element at front of Queue is display.
{
    printf("Queue's Front Element is %d",queue ->arr[(queue->front)+1]);
    printf("\n\n");
}

void get_rear(struct Queue* queue)      //Defination of get rear function, in this value of element at rear of Queue is display.
{
    printf("Queue's Rear element is %d",queue ->arr[queue ->rear]);
    printf("\n\n");
}

void sorting(struct Queue* queue)       //Defination of Sortiong function ,which is use to sort the remainging elements in the Queue.
{
    int temp1,temp2,temp3;
    temp1 = (queue ->front)-1;
    temp2 = queue ->front;
    

    while(temp1 != queue ->rear)
    {
    temp3 = queue->arr[temp1];
    queue->arr[temp1] = queue->arr[temp2];
    queue->arr[temp2] = temp3;
    temp1++;
    temp2++;
    }
}