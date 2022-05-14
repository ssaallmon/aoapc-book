#include <algorithm>
#include <cstdio>

const int maxn = 1e5 + 5;
int n, l, a[maxn];

int pack() {
  int q = 0, i = 0, j = n - 1;
  std::sort(a, a + n);
  while(i <= j) {
    if(a[i] + a[j--] <= l) ++i;
    ++q;
  }
  return q;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &l);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("%d%s", pack(), T ? "\n\n" : "\n");
  }
  return 0;
}
