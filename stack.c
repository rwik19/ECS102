//Implements a dynamic stack.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    int index;
    struct node* next;
}Stack;

void Push(Stack **, int);
int Pop(Stack **);
int Peek(Stack *);
int search(Stack *, int);
void display(Stack *);

int main(void)
{
    Stack* stack = NULL;
    int value, o = 1, index;
    while(o)
    {
        printf("1.Push   2.Pop   3.Peek   4.Search  5.Display   0.Exit\n");
        scanf("%d", &o);
        switch(o)
        {
            case 1: printf("Value = ");
                    scanf("%d", &value);
                    Push(&stack, value);
                    break;
            
            case 2: if(stack!=NULL)
                    {
                        index = stack->index;
                        value = Pop(&stack);
                        printf("Value = %d at index = %d\n", value, index);
                    }
                    else
                    {
                        printf("Stack Underflow...\n");
                    }
                    break;
            
            case 3: if(stack!=NULL)
                    {
                        value = Peek(stack);
                        index = stack->index;
                        printf("Value = %d, Index = %d\n", value, index);
                    }
                    else
                    {
                        printf("Stack is empty.\n");
                    }
                    break;
            
            case 4: printf("Value = ");
                    scanf("%d", &value);
                    index = search(stack, value);
                    if(index>=0)
                    {
                        printf("Value = %d present at index = %d\n", value, index);
                    }
                    else
                    {
                        printf("Value was not found in stack.\n");
                    }
                    break;

            case 5: display(stack);
                    break;
            
            case 0: printf("Exitting stack...\n");
                    break;
            default: printf("Enter a valid option.\n");       
        }
    }
}

void Push(Stack **top, int value)
{
    Stack *new = malloc(sizeof(Stack));
    if(new == NULL)
    {
        printf("Stack Overflow...\n");
        return;
    }
    if(*top == NULL)
    {
        new->value = value;
        new->index = 0;
        new->next = NULL;
    }
    else
    {
        new->value = value;
        new ->index = ((*top)->index)+1;
        new->next = *top;
    }
    *top = new;
}

int Pop(Stack **top)
{
    Stack *temp = *top;
    int value;
    *top = (*top)->next;
    value = temp->value;
    free(temp);
    return value;
}

int Peek(Stack *top)
{
    return top->value;
}

int search(Stack *top, int value)
{
    Stack *ptr = top;
    if(ptr == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    while(ptr->next != NULL)
    {
        if(ptr->value == value)
        {
            return ptr->index; 
        }
        ptr = ptr->next;
    }
    if(ptr->value == value)
        {
            return ptr->index; 
        }
    
    return -1;
}

void display(Stack *top)
{
    Stack *ptr = top;
    if(ptr == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("\n");
    while(ptr->next != NULL)
    {
        printf("%d  ", ptr->value);
        ptr = ptr->next;
    }
    printf("%d\n\n", ptr->value);
}
