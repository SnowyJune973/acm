#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

#define ZERO(x) (fabs(x) < eps)

using namespace std;

constexpr int MAX = 256;
constexpr double eps = 1e-8;
constexpr double err = 1e-16;

double mat[MAX][MAX];
int r[MAX];

int gauss(double a[MAX][MAX], int n, int m) {
    int i, j, k, p, cnt = 0;
	double t;
    memset(r, -1, sizeof(r));
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
        r[i] = cnt;
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

struct DSU {
  int pre[MAX];

  void Init() {
    memset(pre, -1, sizeof(pre));
  }

  int Find(int x) {
    return pre[x] < 0 ? x : pre[x] = Find(pre[x]);
  }

  bool Union(int a, int b) {
    int ra = Find(a), rb = Find(b);
    if (ra == rb) return false;
    if (pre[ra] < pre[rb]) {
      pre[ra] += pre[rb]; pre[rb] = ra;
    } else {
      pre[rb] += pre[ra]; pre[ra] = rb;
    }
    return true;
  }
} dsu;

int id[MAX], xx[MAX][MAX];
vector<int> adj[MAX];

void Init(int n) {
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      xx[i][j] = cur++;
    }
  }
}

void DFS(int x, int& cur_id) {
  if (~id[x]) return;
  id[x] = cur_id++;
  for (int y : adj[x]) {
    if (~id[y]) continue;
    DFS(y, cur_id);
  }
}

inline int MatIdx(int a, int b) {
  if (id[a] > id[b]) swap(a, b);
  return xx[id[a]][id[b]];
}

double Solve(int n, int src, int dst) {
  if (src == dst) return 1.0;
  dsu.Init();
  for (int x = 0; x < n; ++x) {
    for (int y : adj[x]) {
      dsu.Union(x, y);
    }
  }
  if (dsu.Find(src) != dsu.Find(dst)) return -1.0;
  memset(id, -1, sizeof(id));
  int cnt = 0;
  DFS(src, cnt);
  Init(cnt);
  memset(mat, 0, sizeof(mat));
  int m = cnt * (cnt + 1) / 2;
  for (int i = 0; i < m; ++i) {
    mat[i][i] = 1.0; mat[i][m] = 1.0;
  }
  for (int u = 0; u < n; ++u) {
    if (id[u] == -1) continue;
    for (int v = u + 1; v < n; ++v) {
      if (id[v] == -1) continue;
      double p = 1.0 / adj[u].size(), q = 1.0 / adj[v].size();
      for (int x : adj[u]) {
        for (int y : adj[v]) {
          mat[MatIdx(u, v)][MatIdx(x, y)] -= p * q;
        }
      }
    }
  }
  gauss(mat, m, m);
  int st = MatIdx(src, dst);
  return mat[r[st]][m] > 1e10 ? -1.0 : mat[r[st]][m];
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
    double ans = Solve(n, src, dst);
    if (ans < 0) printf("never meet\n");
    else printf("%.8f\n", ans - 1.0);
  }
  return 0;
}
