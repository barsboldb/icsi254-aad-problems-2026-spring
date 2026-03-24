#include "DS.h"


void q_push(Queue *p, int x)
{
    Elm *new_elm = malloc(sizeof(Elm));
    new_elm->x = x;
    new_elm->next = NULL;
    if (p->tail) p->tail->next = new_elm;
    else p->head = new_elm;
    p->tail = new_elm;
    p->len++;
}


void q_pop(Queue *p)
{
    if (p->head == NULL) return;
    Elm *temp = p->head;
    p->head = p->head->next;
    if (p->head == NULL) p->tail = NULL;
    free(temp);
    p->len--;
}

void q_print(Queue *p)
{
    Elm *curr = p->head;
    while (curr) {
        printf("%d\n", curr->x);
        curr = curr->next;
    }
}
