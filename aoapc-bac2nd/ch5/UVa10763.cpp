#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5e5 + 5;
int n, A, B, num[maxn];

int main() {
  while (scanf("%d", &n) && n) {
    int ok = 1;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &A, &B);
      --num[A];
      ++num[B];
    }
    for (int i = 0; i < maxn; ++i) {
      if (num[i]) {
        ok = 0;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
