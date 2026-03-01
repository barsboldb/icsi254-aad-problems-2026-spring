#include "DS.h"


void l_push_back(List *p, int x, float weight)
{
    Elm *new_elm = malloc(sizeof(Elm));
    new_elm->x = x;
    new_elm->weight = weight;
    new_elm->next = NULL;
    if (p->tail) p->tail->next = new_elm;
    else p->head = new_elm;
    p->tail = new_elm;
    p->len++;
}


void l_push_front(List *p, int x, float weight)
{
	Elm *new_elm = malloc(sizeof(Elm));
    new_elm->x = x;
    new_elm->weight = weight;
    new_elm->next = p->head;
    p->head = new_elm;
    if (p->tail == NULL) p->tail = new_elm;
    p->len++;
}


void l_insert(List *p, int x, float weight, int pos)
{
	if (pos <= 0) {
    l_push_front(p, x, weight);
    return;
    } else if (pos >= p->len) {
        l_push_back(p, x, weight);
        return;
    }
    Elm *new_elm = malloc(sizeof(Elm));
    new_elm->x = x;
    new_elm->weight = weight;

    Elm *curr = p->head;
    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }

    new_elm->next = curr->next;
    curr->next = new_elm;
    p->len++;
}


void l_pop_front(List *p)
{
	if (p->head == NULL) return;
    Elm *temp = p->head;
    p->head = p->head->next;
    if (p->head == NULL) p->tail = NULL;
    free(temp);
    p->len--;
}


void l_pop_back(List *p)
{
	if (p->head == NULL) return;
    if (p->head == p->tail) {
        free(p->head);
        p->head = p->tail = NULL;
    } else {
        Elm *curr = p->head;
        while (curr->next != p->tail) {
          curr = curr->next;
        }
        free(p->tail);
        p->tail = curr;
        p->tail->next = NULL;
    }
    p->len--;
}


void l_erase(List *p, int pos)
{
	if (pos < 0 || pos >= p->len) return;
    if (pos == 0) {
        l_pop_front(p);
        return;
    }
    Elm *curr = p->head;
    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }
    Elm *temp = curr->next;
    curr->next = temp->next;
    if (temp == p->tail) p->tail = curr;
    free(temp);
    p->len--;
}


void l_print(List *p)
{
    Elm *curr = p->head;
    while (curr) {
        printf("%d\n", curr->x);
        curr = curr->next;
    }
}


Elm *l_search(List *p, int x)
{
	Elm *curr = p->head;
    while (curr) {
        if (curr->x == x) return curr;
        curr = curr->next;
    }
    return NULL;
}
