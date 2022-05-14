#include <cstdio>
#include <cstring>

const int maxl = 105;
char bottom[maxl], top[maxl];

int min(const int &i, const int &j) { return i < j ? i : j; }

int kickdown(char *s1, char *s2) {
  int n1 = strlen(s1), n2 = strlen(s2), len = 0;
  for(int i = 0; i <= n1; ++i) {
    int ok = 1;
    for(int j = 0; ok && i + j < n1 && j < n2; ++j)
      if(s1[i + j] - '0' + s2[j] - '0' > 3) ok = 0;
    if(ok) {
      len = n1 - i > n2 ? n1 : i + n2;
      break;
    }
  }
  return len;
}

int main() {
  while(scanf("%s%s", bottom, top) == 2)
    printf("%d\n", min(kickdown(bottom, top), kickdown(top, bottom)));
  return 0;
}
