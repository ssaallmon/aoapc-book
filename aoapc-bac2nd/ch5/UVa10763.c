#include <stdio.h>
#include <string.h>
#define MAXN 500005

int A, B, num[MAXN];

int main() {
  int n;
  while(scanf("%d", &n) && n) {
    int ok = 1;
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; ++i) {
      scanf("%d%d", &A, &B);
      --num[A]; ++num[B];
    }
    for(int i = 0; i < MAXN; ++i)
      if(num[i]) { ok = 0; break; }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
