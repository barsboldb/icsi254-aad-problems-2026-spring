#include "DS.h"

void s_push(Stack *p, int x)
{
    Elm *new_elm = malloc(sizeof(Elm));
    new_elm->x = x;
    new_elm->next = p->top;
    p->top = new_elm;
    p->len++;
}

void s_pop(Stack *p)
{
    if (p->top == NULL) return;
    Elm *temp = p->top;
    p->top = p->top->next;
    free(temp);
    p->len--;
}

void s_print(Stack *p)
{
    Elm *curr = p->top;
    while (curr) {
        printf("%d\n", curr->x);
        curr = curr->next;
    }
}
