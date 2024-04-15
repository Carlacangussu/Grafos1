#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 2010

bool visit[MAXSIZE];
bool adj[MAXSIZE][MAXSIZE];

int n;

void dfs(int x) {
    visit[x] = true;
    for (int i = 1; i <= n; ++i) {
        if (adj[x][i] && !visit[i]) {
            dfs(i);
        }
    }
}

int main() {
    int u, v, p, m;
    while (scanf("%d %d", &n, &m), m && n) {
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &p);
            if (p == 1) {
                adj[u][v] = true;
            } else {
                adj[u][v] = adj[v][u] = true;
            }
        }

        bool todos_visitados = true;
        for (int i = 1; i <= n; ++i) {
            memset(visit, 0, sizeof(visit));
            dfs(i);
            for (int j = 1; j <= n; ++j) {
                if (!visit[j]) {
                    todos_visitados = false;
                    break;
                }
            }
            if (!todos_visitados) {
                break; 
            }
        }
        printf("%d\n", todos_visitados ? 1 : 0);
    }
    return 0;
}
