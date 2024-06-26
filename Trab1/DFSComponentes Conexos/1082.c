#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 35

char no[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];
int visit[MAXSIZE];

int tam;
int v, e;

void dfs(int x) {
	visit[x] = 1;
	no[tam++] = x;
	for (int i = 0; i < v; ++i) {
		if (adj[x][i] && !visit[i]) {
			dfs(i);
		}
	}
}

int compara(const void *a, const void *b) {
    char charA = *((char*)a);
    char charB = *((char*)b);

    if (charA == charB) {
        return 0;
    } else if (charA > charB) {
        return 1;
    } else {
        return -1;	
    }
}

int main () {
	char a, b;
	int n;
    int caso = 0;

	scanf("%d", &n);

	while (n > 0) {
        n--;
        caso++;
		scanf("%d %d", &v, &e);

		for (int i = 0; i < e; ++i) {
			scanf(" %c %c", &a, &b);
			adj[a - 'a'][b - 'a'] = 1;
			adj[b - 'a'][a - 'a'] = 1;
		}

		printf("Case #%d:\n", caso);
		int componentes = 0;
		for (int i = 0; i < v; ++i) {
			if (!visit[i]) {
				++componentes, dfs(i);
				qsort(no, tam, sizeof(char), compara);
				for (int j = 0; j < tam; ++j){
					printf("%c,", no[j] + 'a');
                }
				printf("\n");
			}
			tam = 0;
		}
		printf("%d connected components\n", componentes);
		printf("\n");
		memset(visit, 0, sizeof(visit));
		memset(adj, 0, sizeof(adj));
	}
}