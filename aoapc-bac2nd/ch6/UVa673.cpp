#include <cstdio>
#include <cstring>

const int maxl = 130;
char str[maxl], s[maxl];

int check() {
  int top = -1, m = strlen(str);
  for (int i = 0; i < m - 1; ++i) {
    if (str[i] == '(' || str[i] == '[')
      s[++top] = str[i];
    else if (str[i] == ')' && s[top] == '(' || str[i] == ']' && s[top] == '[')
      --top;
    else
      return 0;
  }
  return top < 0;
}

int main() {
  int n;
  scanf("%d", &n);
  getchar();
  while (n--) {
    fgets(str, maxl, stdin);
    memset(s, 0, sizeof(s));
    puts(check() ? "Yes" : "No");
  }
  return 0;
}
