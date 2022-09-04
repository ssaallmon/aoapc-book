#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1e6 + 5;
int A[maxn], vis[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, ans = 0, L = 0, R = 0;
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
    while(R < n) {
      while(R < n && !vis[A[R]]) vis[A[R++]] = 1; 
      ans = std::max(ans, R - L);
      vis[A[L++]] = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
