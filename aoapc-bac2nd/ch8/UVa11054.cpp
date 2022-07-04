#include <cstdio>
#include <cstdlib>

int a, b, n;
long long ans;

int main() {
  while(scanf("%d", &n) && n) {
    b = ans = 0;
    for(int i = 0; i < n; ++i) {
      scanf("%d", &a);
      b += a;
      ans += abs(b);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
