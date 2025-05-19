#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

enum error{
    noerror,
    underflow,
    overflow
};

typedef struct{
    int top;
    int size;
    int *p;
} stack;

int stack_empty(stack *S)
{
    if(S->top == -1)
        return TRUE;
    else
        return FALSE;
}

enum error push(stack *S, int x)
{
    if(S->top == S->size - 1)
        return overflow;
    else
    {
        S->top++;
        (S->p)[S->top] = x;
        return noerror;
    }
}

enum error pop(stack *S, int *ret)
{
    int tmp;
    if(stack_empty(S))
        return underflow;
    else
    {
        tmp = S->top;
        S->top--;
        *ret=(S->p)[tmp];
        return noerror;
    }
}

void init_stack(stack *S, int size)
{
    S->p = malloc(size * sizeof(int));
    S->top = -1;
    S->size = size;
}

int main()
{
    stack S;
    int size;
    int receive_value;
    char option;
    int quite = 1;
    int x;

    printf("Please input number of elements of stack: \n");
    scanf("%d", &size);
    printf("size is %d\n", size);

    init_stack(&S, size);

    printf("p - push\n,o - pop\n,q - quite\n");
    printf("Enter option:\n");
    
    while((option = getchar()) == '\n');

    while(quite)
    {
        switch(option)
        {
            case 'p':
                printf("Insert: ");
                scanf("%d",&x);
                if(push(&S, x) == overflow)
                    printf("stack is full with %d elements\n", S.top + 1);
                break;
            case 'o':
                if(pop(&S, &receive_value) == underflow)
                {
                    printf("Stack is empty\n");
                    break;
                }
                printf("pop: %d\n", receive_value);
                break;
            case 'q':
                quite = 0;
                break;
            default:
                break;    
        }
        printf("Enter option:\n");
        while(quite == 1 && (option = getchar()) == '\n');
    }
    free(S.p);
    return 0;
}