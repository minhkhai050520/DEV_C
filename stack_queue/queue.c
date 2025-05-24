#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int head;
    int tail;
    int *pt;
} queue;

void enqueue(queue *q, int x);
int dequeue(queue *q);
void initqueue(queue *q, int size);

int main()
{
    queue Q;
    int size;
    char c;
    printf("Enter a size of the stack: ");
    scanf("%d", &size);
    initqueue(&Q, size);

    printf("i - insert\np - pop\n");
    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case 'i':
            {
                int a;
                printf("input element: ");
                scanf("%d", &a);
                enqueue(&Q, a);
                printf("Q.head: %d\n", Q.head);
                printf("Q.tail: %d\n", Q.tail);
                printf("Q.size: %d\n", Q.size);
                break;
            }
            case 'p':
                printf("dequeue: %d\n", dequeue(&Q));
                printf("Q.head: %d\n", Q.head);
                printf("Q.tail: %d\n", Q.tail);
                printf("Q.size: %d\n", Q.size);
                break;
            default:
                break;
        }

        if(c == 'q')
            break;
    }

    
    free(Q.pt);
    return 0;
}

void initqueue(queue *q, int size)
{
    q->pt = malloc(size * sizeof(int));
    q->size = size;
    q->head = 0;
    q->tail = 0;
}

void enqueue(queue *q, int x)
{
    q->pt[q->tail] = x;

    if(q->tail == (q->size - 1))
        q->tail = 0;
    else
        q->tail += 1;
}

int dequeue(queue *q)
{
    int x;
    x = q->pt[q->head];

    if(q->head == (q->size -1))
        q->head = 0;
    else
        q->head += 1;
    return x;
}