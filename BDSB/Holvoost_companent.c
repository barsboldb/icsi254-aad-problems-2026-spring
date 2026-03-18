/**"Sanaa: 
1. bukh node-iig jagsaalt=0 gej ekhluulne
2. Node bur deer davtana:
- Khervee jagsaalt bish (baikhgui) bol DFS ekhluulne. Ene n neg buten componentiig khamaarna.
- C-buyu component-iin toog negeer nemegduulne**/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int arr[MAX][MAX];
int jagsaalt[MAX];
int n;
void dfs(int v){
    jagsaalt[v]=1;
    for (int i=0; i<n; i++){
        if (arr[v][i] && !jagsaalt[i]){
            dfs(i);
        }
    }
}
int CompanentsToo(){
    int c=0;
    for (int i=0; i<n; i++){
        if (!jagsaalt[i]){
            dfs(i);
            c++;
        }
    }
    return c;
}
int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Companents: %d\n", CompanentsToo());
}
