#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* prev;
    struct node* next;
    int key;
} node;

typedef struct list{
    node* head;
} list;

/* Search a node with key value */
node* list_search(list* L, int key);

/* add a node to the head of the linked list */
void list_prepend(list* L, node* x);

/* Insert node x following y */
void list_insert(node* x, node* y);

/* Delete a not x out of the list */
void list_detele(list* L, node* x);

int main()
{
    list L;
    L.head = NULL;
    char c;
    int key;
    node *x = NULL;
    int node_index;

    printf("s - search\np - prepend\ni - insert\nq - quit\n");

    while(1)
    {
        printf("Enter command: ");
        while((c = getchar()) == '\n');
        switch (c)
        {
            case 's':
            {
                printf("input key to search:\n");
                scanf("%d", &key);
                
                if(list_search(&L, key) != NULL)
                    printf("node with key = %d is found in the list\n", key);
                else
                    printf("node with key = %d does not exist\n", key);

                break;
            }
            case 'p':
            {
                printf("Input key to prepend\n");
                scanf("%d", &key);
                x = malloc(sizeof(node));
                x->key = key;
                list_prepend(&L, x);
                break;
            }
            case 'i':
            {
                printf("Enter key of node x:\n");
                scanf("%d", &key);
                x = malloc(sizeof(node));
                x->key = key;
                printf("Insert x follow the node with key = ");
                getchar();
                scanf("%d", &key);
                if(list_search(&L, key) != NULL)
                {
                    list_insert(x, list_search(&L, key));
                    printf("node with key = %d is added in the list\n", key);
                }
                else
                    printf("invalid key\n");
                break;
            }
            case 'q':
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}

node* list_search(list* L, int key)
{
    node* x;
    x = L->head;

    while(x != NULL && x->key != key)
        x = x->next;
    return x;
}

void list_prepend(list* L, node* x)
{
    x->next = L->head;
    x->prev = NULL;

    if(L->head != NULL)
        (L->head)->prev = x;
    L->head = x;
}

void list_insert(node* x, node* y)
{
    x->next = y->next;
    x->prev = y;

    if(y->next != NULL)
        (y->next)->prev = x;
    y->next = x;
}

void list_detele(list* L, node* x)
{
    if(x->prev != NULL)
        (x->prev)->next = x->next;
    else
        L->head = x->next;
    
    if(x->next != NULL)
        (x->next)->prev = x->prev;
}