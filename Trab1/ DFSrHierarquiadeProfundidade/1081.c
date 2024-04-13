#include <stdio.h>
#include <string.h>

#define MAX 30

int vertice;
char espacos[MAX];
int visitado[MAX];
int adjacentes[MAX][MAX];

int dfs(int u) {
    visitado[u] = 1;
    strcat(espacos, "  ");
    int novaConexao = 0;

    for (int i = 0; i < vertice; ++i) {
        if (adjacentes[u][i]) {
            if (!visitado[i]) {
                printf("%s%d-%d pathR(G,%d)\n", espacos, u, i, i);
                novaConexao = 1;
                dfs(i);
                espacos[strlen(espacos) - 2] = '\0';
            } else {
                printf("%s%d-%d\n", espacos, u, i);
            }
        }
    }
    return novaConexao;
}

int main() {
    int n, e, caso = 0;
    scanf("%d", &n);
    while (n > 0) {
        n--;
        scanf("%d %d", &vertice, &e);
        memset(visitado, 0, sizeof(visitado));
        memset(adjacentes, 0, sizeof(adjacentes));

        for (int i = 0; i < e; ++i) {
            int u, w;
            scanf("%d %d", &u, &w);
            adjacentes[u][w] = 1;
        }

        printf("Caso %d:\n", ++caso);

        for (int i = 0; i < vertice; ++i) {
            espacos[0] = '\0';
            if (!visitado[i] && dfs(i)) {
                printf("\n");
            }
        }
    }
    return 0;
}
