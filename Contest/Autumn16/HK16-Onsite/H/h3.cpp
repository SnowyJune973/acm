#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

#define ZERO(x) (fabs(x) < eps)

using namespace std;

const int MAX = 1256;
const long double eps = 1e-8;
const long double err = 1e-16;

const long double ONE = 1.0;

long double mat[MAX][MAX];

int gauss(long double a[MAX][MAX], int n, int m) {
    int i, j, k, p, cnt = 0;
	long double t;
    for (i = 0; i < m; ++i) {
        for (j = p = cnt; j < n; ++j) {
            if (a[p][i] < a[j][i]) p = j;
        }
        if (ZERO(a[j = p][i])) {
          a[j][i] = err;
        }
        if (j != cnt) {
            for (k = 0; k <= m; ++k) swap(a[cnt][k], a[j][k]);
        }
        for (t = a[cnt][j = i]; j <= m; ++j) a[cnt][j] /= t;
        for (j = cnt + 1; j < n; ++j) {
            for (t = a[j][k = i]; k <= m; ++k) {
                a[j][k] -=  t * a[cnt][k];
            }
        }
        ++cnt;
    }

    // for (i = cnt; i < n; ++i) {
    //     if (!ZERO(a[i][m])) return -1;
    // }
    // if (cnt < m) return 0;

    for (i = 1; i < cnt; ++i) {
        for (j = 0; j < i; ++j) {
            for (t = a[j][k = i]; k <= m; ++k) {
                a[j][k] -= t * a[i][k];
            }
        }
    }

    return 1;
}


int xx[MAX][MAX];
vector<int> adj[MAX];

void Init(int n) {
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      xx[i][j] = cur++;
    }
  }
}


inline int MatIdx(int a, int b) {
  if (a > b) swap(a, b);
  return xx[a][b];
}

long double Solve(int n, int src, int dst) {
  if (src == dst) return 1.0;
  int m = n * (n + 1) / 2;
  Init(n);
  memset(mat, 0, sizeof(mat));
  for (int i = 0; i < m; ++i) {
    mat[i][i] = ONE; mat[i][m] = ONE;
  }
  for (int u = 0; u < n; ++u) {
    for (int v = u + 1; v < n; ++v) {
      if (adj[u].empty() || adj[v].empty()) {
        mat[MatIdx(u, v)][MatIdx(u, v)] = err;
      } else {
        long double p = ONE / adj[u].size(), q = ONE / adj[v].size();
        for (int x : adj[u]) {
          for (int y : adj[v]) {
            mat[MatIdx(u, v)][MatIdx(x, y)] -= p * q;
          }
        }
      }
    }
  }
  // for (int i = 0; i < m; ++i) {
  //   for (int j = 0; j <= m; ++j) {
  //     printf("%8.4f", mat[i][j]);
  //   }
  //   printf("\n");
  // }
  gauss(mat, m, m);
  // printf("\n");
  // for (int i = 0; i < m; ++i) {
  //   for (int j = 0; j <= m; ++j) {
  //     printf("%8.4f", mat[i][j]);
  //   }
  //   printf("\n");
  // }
  int st = MatIdx(src, dst);
  return fabs(mat[st][m]) > 1e12 ? -1.0 : mat[st][m];
}

int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; ++i) adj[i].clear();
    int a, b, src, dst;
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &a, &b);
      adj[a].push_back(b); adj[b].push_back(a);
    }
    scanf("%d%d", &src, &dst);
    long double ans = Solve(n, src, dst);
    if (ans < 0) printf("never meet\n");
    else cout << setprecision(16) << ans - 1.0 << endl;
  }
  return 0;
}
