#include <stdio.h>
#include <string.h>

int visitados[150];
int adjacentes[150][150];
int n, m;

void dfs(int u) {
    visitados[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (adjacentes[u][i] && !visitados[i]) {
            dfs(i);
        }
    }
}

int main() {
    int t, resposta;
    int caso = 1;

    scanf("%d", &t);
    while (t > 0) {
        scanf("%d %d", &n, &m);
        t--;
        memset(adjacentes, 0, sizeof(adjacentes));
        memset(visitados, 0, sizeof(visitados));

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adjacentes[a][b] = 1;
            adjacentes[b][a] = 1;
        }

        dfs(1);
        resposta = 0;
        printf("Caso #%d: ", caso++);

        for (int i = 1; i <= n; i++) {
            if (!visitados[i]) {
                resposta++;
                dfs(i);
            }
        }

        if (resposta == 0) {
            printf("a promessa foi cumprida\n");
        } else {
            printf("ainda falta(m) %d estrada(s)\n", resposta);
        }
    }
    return 0;
}
