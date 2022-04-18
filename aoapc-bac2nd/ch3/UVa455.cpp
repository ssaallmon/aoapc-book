#include <cstdio>
#include <cstring>

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    char s[85];
    scanf("%s", s);
    int n = strlen(s);
    for (int k = 1; k <= n; ++k) {
      if (n % k) continue;
      int ok = 1;
      for (int i = 1; ok && i < n / k; ++i)
        if (strncmp(s, s + k * i, k)) ok = 0;
      if (ok) {
        printf("%d\n", k);
        break;
      }
    }
    if (N) putchar('\n');
  }
  return 0;
}
