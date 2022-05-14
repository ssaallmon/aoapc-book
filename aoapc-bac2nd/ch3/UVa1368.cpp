#include <cstdio>
#include <cstring>

int m, n, err;
const int maxm = 55;
const int maxn = 1005;
char s[maxm][maxn], ans[maxn];

void hamming_dist() {
  err = 0;
  for(int i = 0; i < n; ++i) {
    int p = 0, num[26];
    memset(num, 0, sizeof(num));
    for(int j = 0; j < m; ++j) ++num[s[j][i] - 'A'];
    for(int j = 0; j < 26; ++j)
      if(num[j] > num[p]) p = j;
    ans[i] = 'A' + p;
    err += m - num[p];
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &m, &n);
    memset(s, 0, sizeof(s));
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < m; ++i) scanf("%s", s[i]);
    hamming_dist();
    printf("%s\n%d\n", ans, err);
  }
  return 0;
}
