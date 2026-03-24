#include "../../graph-structure-c/DS.h"

int check_cycle_dfs(Graph *g, int x, int color[], int pi[]){
	color[x] = GRAY;
	Elm *curr = g->adj[x].head;
    while (curr) {
        if (color[curr->x] == WHITE){
			pi[curr->x] = x;
			if (check_cycle_dfs(g, curr->x, color, pi)) return 1;
		}
        else if (color[curr->x] == GRAY && curr->x != pi[x]){
            return 1;
        }
        curr = curr->next;
    }
	color[x] = BLACK;
    return 0;
}

int check_cycle(Graph *g){
	int color[g->n+1];
    int pi[g->n+1];
	for (int i = 1; i < g->n+1; i++)
	{
		color[i] = WHITE;
        pi[i] = -1;
	}
	for (int i = 1; i < g->n+1; i++)
	{
		if(color[i] == WHITE) if(check_cycle_dfs(g, i, color, pi)==1) return 1;
	}
    return 0;
}


int main(){
    int n, m;
	scanf("%d%d", &n, &m);
	Graph g;
	gr_read(&g, n, m, 0, 0);
    if(check_cycle(&g)){
        printf("Graph has cycle\n");
    } else {
        printf("Graph does not have cycle\n");
    }

    return 0;
}