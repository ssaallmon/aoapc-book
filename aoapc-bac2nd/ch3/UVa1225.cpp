#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, n[10];
    scanf("%d", &N);
    memset(n, 0, sizeof(n));
    for (int i = 1; i <= N; ++i) {
      int v = i;
      while (v) {
        ++n[v % 10];
        v /= 10;
      }
    }
    for (int i = 0; i < 10; ++i) printf(i ? " %d" : "%d", n[i]);
    putchar('\n');
  }
  return 0;
}
