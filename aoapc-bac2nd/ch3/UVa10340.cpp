#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;

int main() {
  char s[maxn], t[maxn];
  while(scanf("%s%s", s, t) == 2) {
    int i = 0, n = strlen(t);
    for(int j = 0; j < n; ++j)
      if(t[j] == s[i]) ++i;
    puts(i == strlen(s) ? "Yes" : "No");
  }
  return 0;
}
