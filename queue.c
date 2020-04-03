//A dynamic queue is implemented with help of a doubly linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
}node;

typedef struct Queue
{
    node *start;
    node *end;
}Queue;

void enque(Queue *,int);
int deque(Queue *);
int peek(Queue);
void display(Queue);

int main(void)
{
    Queue que = {NULL, NULL};
    int value,o=1;
    while(o)
    {
        printf("\n1. Enqueue    2. Dequeue    3. Peek    4. Display    0. Exit\nOption: ");
        scanf("%d",&o);
        switch(o)
        {
            case 1: printf("Value: ");
                    scanf("%d",&value);
                    enque(&que,value);
                    break;
            case 2: printf("Value: %d", deque(&que));
                    break;
            case 3: printf("Value: %d", peek(que));
                    break;
            case 4: display(que);
                    break;
            default: printf("Enter a valid option.\n");
        }
    }
}

void enque(Queue *que,int value)
{
    node *temp = malloc(sizeof(node));
        if(temp == NULL)
        {
            return;
        }
    if((que->start) == NULL)
    {
        que->start = que->end = temp;
        temp->left = temp->right = NULL;
        temp->value = value;
    }
    else if(que->start == que->end)
    {
      que->end = temp;
      que->start->right = temp;
      temp->value = value;
      temp->left = que->start;
      temp->right = NULL;  
    }
    else
    {
        que->end->right = temp;
        temp->left = que->end;
        que->end = temp;
        temp->value = value;
        temp->right = NULL;
    }
}

int deque(Queue *que)
{
    int value;
    node *temp;
    if(que->start == NULL)
    {
        printf("Queue is empty.");
    }
    else if(que->start == que->end)
    {
        value = que->end->value;
        free(que->end);
        que->start = que->end = NULL;
        return value;
    }
    else
    {
        value = que->start->value;
        que->start = que->start->right;
        free(que->start->left);
        que->start->left = NULL;
        return value;
    }
}

int peek(Queue que)
{
    if(que.start==NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        return (que.start)->value;
    }
}

void display(Queue que)
{
    if(que.start==NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    else
    {
        for(node *ptr = (que.start);ptr!=(que.end);ptr=ptr->right)
        {
            printf("%d  ",ptr->value);
        }
        printf("%d\n",que.end->value);
    }
}
