#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 4005;
int n, A[maxn], B[maxn], C[maxn], D[maxn];

int sum() {
  int s[n * n], cnt = 0, ans = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) s[cnt++] = A[i] + B[j];
  sort(s, s + cnt);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      ans += upper_bound(s, s + cnt, -C[i] - D[j]) - lower_bound(s, s + cnt, -C[i] - D[j]);
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
    printf("%d%s", sum(), T ? "\n\n" : "\n");
  }
  return 0;
}
