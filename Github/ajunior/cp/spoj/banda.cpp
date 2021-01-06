#include <cstdio>
#include <cstring>

#define MAXN 112

int A[MAXN][MAXN];

int main() {
  int n, m;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, e;
    scanf(" %d%d%d", &u, &v, &e); u--; v--;
    A[u][v] = A[v][u] = e;
  }

  int res = -1, sol[3];
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      for (int k = j+1; k < n; k++)
	if (A[i][j] + A[i][k] + A[j][k] > res) {
	  res = A[i][j] + A[i][k] + A[j][k];
	  sol[0] = i; sol[1] = j; sol[2] = k;
	}

  printf("%d %d %d\n", sol[0]+1, sol[1]+1, sol[2]+1);

  return 0;
}