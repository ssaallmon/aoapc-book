#include <stdio.h>
#include <string.h>

#define MAXL 105
char s[MAXL], n;

int less(int p, int q) {
  for(int i = 0; i < n; ++i) {
    int v = s[(i+p)%n] - s[(i+q)%n];
    if(v) return v < 0 ? p : q;
  }
  return p;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int ans = 0;
    scanf("%s", s);
    n = strlen(s);
    for(int i = 1; i < n; ++i) ans = less(ans, i);
    for(int i = 0; i < n; ++i) putchar(s[(i+ans)%n]);
    putchar('\n');
  }
  return 0;
}
