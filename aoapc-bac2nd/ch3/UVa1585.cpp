#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[85];
    scanf("%s", s);
    int sum = 0, c = 0, n = strlen(s);
    for (int i = 0; i < n; ++i) s[i] == 'O' ? sum += ++c : c = 0;
    printf("%d\n", sum);
  }
  return 0;
}
