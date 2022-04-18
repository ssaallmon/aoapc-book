#include <cctype>
#include <cstdio>
#include <cstring>

const char *a = "CHON";
const double w[] = {12.01, 1.008, 16.00, 14.01};

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[85];
    scanf("%s", s);
    double sum = 0.;
    int i = 0, n = strlen(s);
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) continue;
      int j = strchr(a, s[i]) - a;
      if (!isdigit(s[i + 1]))
        sum += w[j];
      else {
        if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
          sum += w[j] * ((s[i + 1] - '0') * 10 + (s[i + 2] - '0'));
        else
          sum += w[j] * (s[i + 1] - '0');
      }
    }
    printf("%.3f\n", sum);
  }
  return 0;
}
