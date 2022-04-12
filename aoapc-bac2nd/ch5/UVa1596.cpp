#include <cstdio>
#include <cstring>
#include <map>

const char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct Array {
  int length;
  std::map<int, int> element;
} arr[52];

void init() {
  for (int i = 0; i < 52; ++i) {
    arr[i].length = 0;
    arr[i].element.clear();
  }
}

int hunt(char *s) {
  if (strchr(alpha, s[0])) {
    int idx = hunt(s + 2);
    int a = strchr(alpha, s[0]) - alpha;
    return idx >= 0 && arr[a].element.count(idx) ? arr[a].element[idx] : -1;
  } else {
    int n;
    sscanf(s, "%d", &n);
    return n;
  }
}

int main() {
  char s[85];
  while (scanf("%s", s) && s[0] != '.') {
    init();
    int bug = 0, num = 0;
    do {
      if (bug) continue;
      int a = strchr(alpha, s[0]) - alpha;
      if (strchr(s, '=')) {
        int idx = hunt(s + 2);
        int val = hunt(strchr(s, '=') + 1);
        idx >= 0 && idx < arr[a].length && val >= 0 ? arr[a].element[idx] = val : bug = 1;
      } else {
        int n;
        char c;
        sscanf(s, "%c[%d]", &c, &n);
        arr[a].length = n;
      }
      ++num;
    } while (scanf("%s", s) && s[0] != '.');
    printf("%d\n", bug ? num : 0);
  }
  return 0;
}
