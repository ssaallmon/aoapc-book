#include <cstdio>

int main() {
  char c;
  int q = 1;
  while((c = getchar()) != EOF) {
    if(c == '"') {
      printf(q ? "``" : "''");
      q = !q;
    } else putchar(c);
  }
  return 0;
}
