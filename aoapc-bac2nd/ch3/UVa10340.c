#include <stdio.h>
#include <string.h>
#define MAXN 100005

int main() {
  char s[MAXN], t[MAXN];
  while(~scanf("%s%s", s, t)) {
    int i = 0, n = strlen(t);
    for(int j = 0; j < n; ++j)
      if(t[j] == s[i]) ++i;
    puts(i == strlen(s) ? "Yes" : "No");
  }
  return 0;
}
